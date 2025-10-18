#include "recovery_status.h"
#include <iostream>
#include <string>

void show_recovery_menu() {
    std::cout << "\n===== AuraOS Recovery Menu =====\n";
    std::cout << "1. Wipe cache\n";
    std::cout << "2. Factory reset\n";
    std::cout << "3. Apply update from storage\n";
    std::cout << "4. Restore backup\n";
    std::cout << "5. Mount partitions\n";
    std::cout << "6. Check system integrity\n";
    std::cout << "7. Reboot system\n";
    std::cout << "=================================\n";
}
