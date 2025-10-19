// html/html_logic.cpp
#include "html_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 65536 // 64KB
#define NUM_COLORS 6

const uint32_t colors[NUM_COLORS] = {
    0xFF0000, // vermelho
    0x00FF00, // verde
    0xFFFF00, // amarelo
    0x0000FF, // azul
    0xFF00FF, // magenta
    0x00FFFF  // ciano
};

size_t html_load_file_colored(const char* path, html_char_t* out_buffer, size_t max_len) {
    FILE* f = fopen(path, "r");
    if (!f) return 0;

    size_t bytes_read = fread(out_buffer, 1, max_len, f);
    fclose(f);

    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < bytes_read; ++i) {
        char ch = ((char*)out_buffer)[i];
        out_buffer[i].ch = ch;
        // Cor aleatória que muda a cada chamada
        out_buffer[i].color = colors[rand() % NUM_COLORS];
    }
    return bytes_read;
}
