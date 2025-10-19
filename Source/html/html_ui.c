// html/html_ui.c
#include "html_ui.h"
#include "html_logic.h"
#include "seven_ui.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

static int scroll_x = 0;
static int scroll_y = 0;
static int char_width = 8;
static int char_height = 16;

void html_set_zoom(int zoom_factor) {
    char_width = 8 * zoom_factor;
    char_height = 16 * zoom_factor;
}

void html_draw_colored(html_char_t* buffer, size_t len) {
    int cur_x = -scroll_x;
    int cur_y = -scroll_y;

    for (size_t i = 0; i < len; ++i) {
        if (buffer[i].ch == '\n') {
            cur_x = -scroll_x;
            cur_y += char_height;
            continue;
        }

        if (cur_x >= -char_width && cur_x < SCREEN_WIDTH && cur_y >= -char_height && cur_y < SCREEN_HEIGHT) {
            seven_ui_draw_char(buffer[i].ch, cur_x, cur_y, buffer[i].color);
        }

        cur_x += char_width;
        if (cur_x + char_width > SCREEN_WIDTH) {
            cur_x = -scroll_x;
            cur_y += char_height;
        }
    }
}

void html_scroll(int dx, int dy) {
    scroll_x += dx;
    scroll_y += dy;
    if (scroll_x < 0) scroll_x = 0;
    if (scroll_y < 0) scroll_y = 0;
}

// Função principal
void html_open_and_display(const char* path, int random_per_line) {
    static html_char_t buffer[MAX_FILE_SIZE] = {0};
    static size_t len = 0;
    static size_t line_cache[MAX_FILE_SIZE / 16] = {0}; // cache por linha
    static int first_load = 1;

    if (first_load) {
        len = html_load_file_colored(path, buffer, MAX_FILE_SIZE);
        memset(line_cache, 0, sizeof(line_cache));
        first_load = 0;
    } else {
        html_refresh_colors_cached(buffer, len, line_cache, random_per_line);
    }

    html_draw_colored(buffer, len);
}
