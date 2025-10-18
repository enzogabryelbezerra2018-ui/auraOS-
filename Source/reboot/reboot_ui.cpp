#include "reboot_manager.h"
#include <iostream>
#include <thread>
#include <chrono>

void show_reboot_screen(RebootReason reason) {
    std::cout << "\n=============================\n";
    std::cout << " 🔁  AuraOS está reiniciando... \n";
    std::cout << " Motivo: " << Reboot::get_reason_string(reason) << "\n";
    std::cout << "=============================\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[UI] Tela de reinício exibida.\n";
}
