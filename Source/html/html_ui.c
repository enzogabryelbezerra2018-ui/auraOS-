// html/html_ui.c
#include "html_ui.h"
#include "html_logic.h"
#include "seven_ui.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240
#define CHAR_WIDTH    8
#define CHAR_HEIGHT   16

static int scroll_offset = 0;

void html_draw_colored(html_char_t* buffer, size_t len) {
    int cur_x = 0;
    int cur_y = -scroll_offset; // inicia com offset para scroll

    for (size_t i = 0; i < len; ++i) {
        if (buffer[i].ch == '\n') {
            cur_x = 0;
            cur_y += CHAR_HEIGHT;
            continue;
        }

        // Desenha apenas se estiver dentro da tela
        if (cur_y >= 0 && cur_y < SCREEN_HEIGHT) {
            seven_ui_draw_char(buffer[i].ch, cur_x, cur_y, buffer[i].color);
        }

        cur_x += CHAR_WIDTH;
        if (cur_x + CHAR_WIDTH > SCREEN_WIDTH) {
            cur_x = 0;
            cur_y += CHAR_HEIGHT;
        }
    }
}

// Função para aumentar scroll
void html_scroll_down(int pixels) {
    scroll_offset += pixels;
}

// Função para diminuir scroll
void html_scroll_up(int pixels) {
    scroll_offset -= pixels;
    if (scroll_offset < 0) scroll_offset = 0;
}

// Função principal para abrir e desenhar HTML
void html_open_and_display(const char* path) {
    html_char_t buffer[MAX_FILE_SIZE] = {0};
    size_t len = html_load_file_colored(path, buffer, MAX_FILE_SIZE);

    html_draw_colored(buffer, len);
}
