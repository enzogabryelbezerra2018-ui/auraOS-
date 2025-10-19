// include/html_logic.h
#ifndef HTML_LOGIC_H
#define HTML_LOGIC_H

#include <string>
#include <vector>
#include <cstdint>

// Estrutura de caractere colorido para renderização na UI
struct HtmlChar {
    char ch;
    uint32_t color;
};

// Função principal: navega para a URL, baixa HTML e prepara buffer
void navigate_to(const std::string& url);

// Retorna o buffer de caracteres para a UI desenhar
const std::vector<HtmlChar>& get_html_buffer();

// Renderiza HTML em memória (chama interpretador Java)
void render_page(const std::string& html_data);

#endif // HTML_LOGIC_H
