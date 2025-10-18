#include "recovery_status.h"
#include <iostream>
#include <thread>
#include <chrono>

void start_recovery_mode() {
    std::cout << "\n=====================================\n";
    std::cout << "🔧 AuraOS Recovery Mode Iniciado\n";
    std::cout << "Segure VOL- + Power para sair.\n";
    std::cout << "=====================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}
