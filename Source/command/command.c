#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Protótipo do reboot (da pasta reboot)
void reboot_system();

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void run_no_command_mode() {
    while(1) {
        clear_screen();

        // Centraliza "No command."
        printf("\n\n\n\n\n");
        printf("                 No command.\n");
        printf("\n\n");

        // Executa o reboot da pasta reboot
        reboot_system();

        // Pequeno delay para não travar totalmente
        usleep(500000); // 0.5 segundos
    }
}
