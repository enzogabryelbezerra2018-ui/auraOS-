#include "../reboot/reboot_manager.h"
#include "../recovery/recovery_status.h"
#include <iostream>
#include <thread>
#include <chrono>

// Protótipos vindos do Recovery
void start_recovery_mode();
void show_recovery_menu();

// Módulo de integração
namespace SystemIntegration {

    // Simula o status de inicialização do sistema
    bool system_boot_failed = false;

    // Função chamada ao reiniciar
    void handle_reboot_with_recovery(RebootReason reason) {
        std::cout << "[Integration] Verificando se é necessário entrar no Recovery...\n";

        // Se foi erro do kernel, atualização ou falha de boot, entra no recovery
        if (reason == RebootReason::KERNEL_PANIC ||
            reason == RebootReason::UPDATE_COMPLETE && system_boot_failed) {

            std::cout << "[Integration] Entrando em modo Recovery automático...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Chama a inicialização do Recovery
            start_recovery_mode();
            show_recovery_menu();
        } else {
            std::cout << "[Integration] Reinício normal do AuraOS.\n";
        }
    }

    // Simula o boot do sistema
    void boot_system() {
        std::cout << "[System] Iniciando boot do AuraOS...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        if (system_boot_failed) {
            std::cout << "[System] Falha no boot detectada!\n";
            handle_reboot_with_recovery(RebootReason::KERNEL_PANIC);
        } else {
            std::cout << "[System] Boot concluído com sucesso.\n";
        }
    }
}
