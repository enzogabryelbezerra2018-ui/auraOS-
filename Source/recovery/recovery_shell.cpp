#include <iostream>
#include <string>

void start_recovery_shell() {
    std::cout << "\n[AuraShell] Modo de linha de comando Recovery.\n";
    std::cout << "Digite 'help' para comandos disponíveis.\n";
    std::string cmd;
    while(true) {
        std::cout << "recovery> ";
        std::getline(std::cin, cmd);
        if(cmd == "exit") break;
        else if(cmd == "help") {
            std::cout << "Comandos: wipe, reset, update, reboot, exit\n";
        } else if(cmd == "wipe") {
            std::cout << "[Shell] Wipe cache executado.\n";
        } else {
            std::cout << "[Shell] Comando não reconhecido.\n";
        }
    }
}
