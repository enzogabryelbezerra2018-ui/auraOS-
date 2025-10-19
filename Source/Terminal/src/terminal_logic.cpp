// src/terminal_logic.cpp
#include "terminal.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>
#include <iostream>

static std::string g_linux_root = "storage/linux-root"; // default
static std::string g_qemu_bin = "/usr/bin/qemu-x86_64"; // ajuste conforme necessário
static std::vector<std::string> g_history;

// Helpers
static bool file_exists(const std::string& path) {
    struct stat st;
    return (stat(path.c_str(), &st) == 0);
}

// Split into argv-like vector (naive, não trata quotes complexos)
static std::vector<std::string> split_args(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> out;
    std::string tok;
    while (iss >> tok) out.push_back(tok);
    return out;
}

// Execute external process and capture stdout+stderr. Returns exit code.
static int run_proc_capture(const std::vector<std::string>& argv, std::string& out_text) {
    out_text.clear();
    if (argv.empty()) return -1;

    int pipefd[2];
    if (pipe(pipefd) != 0) {
        out_text = std::string("pipe() failed: ") + strerror(errno) + "\n";
        return -1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        out_text = std::string("fork() failed: ") + strerror(errno) + "\n";
        close(pipefd[0]); close(pipefd[1]);
        return -1;
    }

    if (pid == 0) {
        // child: redirect stdout+stderr -> pipefd[1]
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        // close all fds except std*
        for (int fd = 3; fd < 64; ++fd) { /* best-effort close */
            // do nothing if fails
            close(fd);
        }

        // Build argv for execvp
        size_t n = argv.size();
        char** cargv = (char**)malloc(sizeof(char*) * (n + 1));
        for (size_t i = 0; i < n; ++i) cargv[i] = strdup(argv[i].c_str());
        cargv[n] = NULL;

        // execvp
        execvp(cargv[0], cargv);
        // If execvp returns, error
        fprintf(stderr, "exec failed: %s\n", strerror(errno));
        _exit(127);
    } else {
        // parent: read pipe
        close(pipefd[1]);
        char buf[4096];
        ssize_t r;
        while ((r = read(pipefd[0], buf, sizeof(buf))) > 0) {
            out_text.append(buf, (size_t)r);
        }
        close(pipefd[0]);
        int status = 0;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) return WEXITSTATUS(status);
        return -1;
    }
}

// Public API
void terminal_init(const std::string& linux_root_path, const std::string& qemu_bin_path) {
    if (!linux_root_path.empty()) g_linux_root = linux_root_path;
    if (!qemu_bin_path.empty()) g_qemu_bin = qemu_bin_path;
}

const std::vector<std::string>& terminal_get_history() {
    return g_history;
}

std::string terminal_execute_command(const std::string& line) {
    std::string trimmed = line;
    // trim CR/LF
    while (!trimmed.empty() && (trimmed.back() == '\n' || trimmed.back() == '\r')) trimmed.pop_back();
    if (trimmed.empty()) return "";

    g_history.push_back(trimmed);

    // Parse command and args
    auto toks = split_args(trimmed);
    if (toks.empty()) return "";

    // Handle builtins that we run natively inside AuraOS (clear, help)
    if (toks[0] == "help") {
        return std::string(
            "Terminal AuraOS (exec via QEMU)\n"
            "Comandos executados como binarios Linux reais se existentes em " ) + g_linux_root + "/bin\n"
            "Comandos built-in: help, clear, exit\n";
    }
    if (toks[0] == "clear") {
        return std::string("\x1B[2J"); // ANSI clear
    }
    if (toks[0] == "exit") {
        return std::string("Exiting terminal\n");
    }

    // If the binary exists inside linux_root/bin, run it via qemu-user
    std::string candidate = g_linux_root + "/bin/" + toks[0];
    if (file_exists(candidate)) {
        // Build argv: [ qemu_bin, -L, linux_root, /bin/cmd, arg1, arg2... ]
        std::vector<std::string> argv;
        argv.push_back(g_qemu_bin);
        argv.push_back("-L");
        argv.push_back(g_linux_root);
        argv.push_back(std::string("/bin/") + toks[0]);
        for (size_t i = 1; i < toks.size(); ++i) argv.push_back(toks[i]);

        std::string out;
        int rc = run_proc_capture(argv, out);
        std::ostringstream oss;
        oss << out;
        oss << "\n[exit code=" << rc << "]\n";
        return oss.str();
    }

    // If not present in linux-root/bin, try to exec directly (maybe qemu in PATH can run it)
    // Try execvp of the command: maybe user installed bin in PATH
    {
        std::vector<std::string> argv2;
        argv2.push_back(toks[0]);
        for (size_t i = 1; i < toks.size(); ++i) argv2.push_back(toks[i]);
        std::string out;
        int rc = run_proc_capture(argv2, out);
        if (rc == 0 || !out.empty()) {
            std::ostringstream oss;
            oss << out;
            oss << "\n[exit code=" << rc << "]\n";
            return oss.str();
        }
    }

    return std::string("Comando não encontrado em ") + g_linux_root + "/bin: " + toks[0] + "\n";
}
