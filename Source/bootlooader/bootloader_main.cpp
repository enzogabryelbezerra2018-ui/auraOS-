#include "boot_menu.h"
#include <vector>
#include <string>

int main() {
    std::vector<std::string> items = {
        "Iniciar AuraOS",
        "Recovery Mode",
        "Debug Mode",
        "Atualizar Bootloader"
    };

    BootMenu menu(items);
    menu.run();

    return 0;
}
