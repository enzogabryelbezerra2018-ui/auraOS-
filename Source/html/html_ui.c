// html/html_ui.c
#include "html_ui.h"
#include "html_logic.h"
#include "seven_ui.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240
#define CHAR_WIDTH    8
#define CHAR_HEIGHT   16

static int scroll_offset = 0;

// Desenha buffer de caracteres coloridos na tela
void html_draw_colored(html_char_t* buffer, size_t len) {
    int cur_x = 0;
    int cur_y = -scroll_offset;

    for (size_t i = 0; i < len; ++i) {
        if (buffer[i].ch == '\n') {
            cur_x = 0;
            cur_y += CHAR_HEIGHT;
            continue;
        }

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

// Scroll vertical
void html_scroll_up(int pixels) {
    scroll_offset -= pixels;
    if (scroll_offset < 0) scroll_offset = 0;
}

void html_scroll_down(int pixels) {
    scroll_offset += pixels;
}

// Atualiza cores em tempo real
void html_refresh_colors(html_char_t* buffer, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        buffer[i].color = colors[rand() % NUM_COLORS];
    }
}

// Função principal: abre, atualiza cores e desenha HTML
void html_open_and_display(const char* path) {
    static html_char_t buffer[MAX_FILE_SIZE] = {0};
    static size_t len = 0;
    static int first_load = 1;

    if (first_load) {
        len = html_load_file_colored(path, buffer, MAX_FILE_SIZE);
        first_load = 0;
    } else {
        html_refresh_colors(buffer, len); // muda cores dinamicamente
    }

    html_draw_colored(buffer, len);
}
