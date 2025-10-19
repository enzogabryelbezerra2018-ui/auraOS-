// src/main.cpp
#include "terminal.h"
#include <string>

// Declaration of UI helper (simple)
void terminal_run_interactive(const std::string& linux_root, const std::string& qemu_bin);

int main(int argc, char** argv) {
    std::string linux_root = "storage/linux-root";
    std::string qemu_bin = "/usr/bin/qemu-x86_64";

    if (argc >= 2) linux_root = argv[1];
    if (argc >= 3) qemu_bin = argv[2];

    terminal_run_interactive(linux_root, qemu_bin);
    return 0;
}
