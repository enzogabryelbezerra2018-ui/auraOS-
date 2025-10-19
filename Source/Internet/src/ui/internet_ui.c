#include "internet_ui.h"
#include "seven_ui.h"

// Desenha barra de endereço, botões, conteúdo
void draw_browser_ui() {
    draw_address_bar();
    draw_navigation_buttons();
    draw_html_content();
}

// Conteúdo HTML: receber de HTMLInterpreter
void draw_html_content() {
    // TODO: implementar render baseado em parse_html()
}
