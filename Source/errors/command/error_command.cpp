#include "error_command.h"
#include "error_parser.h"
#include <iostream>

ErrorCommand::ErrorCommand(ErrorHandler &handler) : error_handler(handler) {}

void ErrorCommand::execute(const std::string &input) {
    std::string cmd = parse_command(input);

    if (cmd == "error list") {
        error_handler.list_errors();
    } else if (cmd == "error clear") {
        error_handler.clear_errors();
    } else if (cmd.rfind("error raise ", 0) == 0) {
        std::string module = cmd.substr(12);
        error_handler.raise_error(AuraError::UNKNOWN_ERROR, module);
    } else {
        std::cout << "[ERROR] Comando inválido: " << cmd << std::endl;
    }
}
