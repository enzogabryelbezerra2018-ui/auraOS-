// include/terminal.h
#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <vector>

// Inicializa subsistema do terminal (liga callbacks de UI se houver)
void terminal_init(const std::string& linux_root_path, const std::string& qemu_bin_path);

// Executa uma linha de comando (entrada do usuário). Retorna saída textual.
std::string terminal_execute_command(const std::string& line);

// Recupera histórico (lista de linhas já executadas)
const std::vector<std::string>& terminal_get_history();

#endif // TERMINAL_H
