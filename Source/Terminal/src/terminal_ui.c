// src/terminal_ui.c
#include "terminal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef SEVEN_UI_AVAILABLE
// Se sua Seven UI fornecer funções, inclua e chame aqui.
// #include "seven_ui.h"
#endif

// UI simples usando stdin/stdout (útil para testes). Em mobile você adapta para Seven UI.
void terminal_run_interactive(const std::string& linux_root, const std::string& qemu_bin) {
    terminal_init(linux_root, qemu_bin);
    char linebuf[1024];

    printf("AuraOS Terminal (exec via QEMU). Rootfs: %s  QEMU: %s\n", linux_root.c_str(), qemu_bin.c_str());
    printf("Digite 'help' para instruções.\n\n");

    while (1) {
        printf("> ");
        fflush(stdout);
        if (!fgets(linebuf, sizeof(linebuf), stdin)) break;
        std::string cmd(linebuf);
        std::string out = terminal_execute_command(cmd);
        if (!out.empty()) {
            printf("%s", out.c_str());
        }
        if (cmd == "exit\n" || cmd == "exit\r\n") break;
    }
}
