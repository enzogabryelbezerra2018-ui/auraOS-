#include "no_main.h"
#include "init.h"
#include "log.h"
#include "../command/command.h"

void run_no_main_mode() {
    // Inicializa módulos mínimos
    init_system();

    // Registra log inicial
    log_message("No main fallback iniciado.");

    // Entra no modo crítico do Command
    run_no_command_mode(); // Tela preta com "No command." e loop de reboot
}
