#include "reboot_manager.h"
#include <iostream>
#include <thread>
#include <chrono>

static RebootReason current_reason = RebootReason::USER_REQUEST;

namespace Reboot {

    void request(RebootReason reason) {
        current_reason = reason;
        std::cout << "[Reboot] Reinício solicitado: " << get_reason_string(reason) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        perform();
    }

    void perform() {
        std::cout << "[Reboot] Salvando estados e encerrando processos..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::cout << "[Reboot] Reiniciando AuraOS..." << std::endl;

        // Aqui seria a chamada real do reboot:
        // system("reboot"); ou chamada direta ao bootloader
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[Reboot] Sistema reiniciado com sucesso!" << std::endl;
    }

    std::string get_reason_string(RebootReason reason) {
        switch(reason) {
            case RebootReason::USER_REQUEST: return "Solicitado pelo usuário";
            case RebootReason::KERNEL_PANIC: return "Kernel Panic";
            case RebootReason::DEBUG_RESET: return "Reinício de depuração";
            case RebootReason::UPDATE_COMPLETE: return "Atualização concluída";
            default: return "Desconhecido";
        }
    }
}
