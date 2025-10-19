// include/internet_ui.h
#ifndef INTERNET_UI_H
#define INTERNET_UI_H

// Desenha toda a interface do navegador: barra de endereço, botões, conteúdo
void draw_browser_ui();

// Desenha apenas o conteúdo HTML (recebido do html_logic)
void draw_html_content();

// Scroll vertical do conteúdo
void html_scroll(int dy);

#endif // INTERNET_UI_H
