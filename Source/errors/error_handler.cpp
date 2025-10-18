#include "error_handler.h"
#include <iostream>

void ErrorHandler::raise_error(AuraError code, const std::string &module) {
    ErrorEntry e;
    e.code = code;
    e.message = get_error_message(code);
    e.module = module;
    errors.push_back(e);
    std::cout << "[ERROR][" << module << "] " << e.message << std::endl;
}

void ErrorHandler::list_errors() const {
    std::cout << "\n=== Lista de Erros Registrados ===\n";
    for (const auto &e : errors) {
        std::cout << "[" << e.module << "] " << e.message << "\n";
    }
    std::cout << "==================================\n";
}

void ErrorHandler::clear_errors() {
    errors.clear();
    std::cout << "[ERROR] Todos os erros foram limpos.\n";
}
