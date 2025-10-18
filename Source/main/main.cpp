#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

// Variáveis de lógica
std::vector<std::string> files;
std::string source_dir = "Source";

int main() {
    std::cout << "Listando arquivos do AuraOS na pasta " << source_dir << ":\n";

    // Lê todos os arquivos dentro da pasta Source
    for (const auto& entry : fs::directory_iterator(source_dir)) {
        if (!entry.is_directory()) {
            files.push_back(entry.path().filename().string());
        }
    }

    // Exibe os arquivos encontrados
    for (size_t i = 0; i < files.size(); i++) {
        std::cout << "[" << i+1 << "] " << files[i] << std::endl;
    }

    std::cout << "\nTotal de arquivos encontrados: " << files.size() << std::endl;

    // Loop de lógica simulando execução
    for (const auto& file : files) {
        std::cout << "Executando módulo: " << file << " ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "Todos os arquivos da pasta Source foram processados.\n";
    return 0;
}
