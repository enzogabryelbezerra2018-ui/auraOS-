// system_font_data.h
// Cabeçalho para a fonte do sistema AuraOS
// Gerado automaticamente a partir das imagens ASCII (32-127)

#ifndef SYSTEM_FONT_DATA_H
#define SYSTEM_FONT_DATA_H

#include <stdint.h>

// Dimensões do caractere
#define SYSTEM_FONT_CHAR_WIDTH  8
#define SYSTEM_FONT_CHAR_HEIGHT 16
#define SYSTEM_FONT_START_CHAR  32
#define SYSTEM_FONT_NUM_GLYPHS  96

// Inclui os dados da fonte gerados no arquivo .inc
#include "system_font_data.inc"

// Estrutura de um glifo (caractere)
typedef struct {
    uint8_t bitmap[SYSTEM_FONT_CHAR_HEIGHT];
} system_glyph_t;

// Ponteiro para os dados da fonte (cada glifo tem 16 bytes)
extern const system_glyph_t g_system_font_data[SYSTEM_FONT_NUM_GLYPHS];

#endif // SYSTEM_FONT_DATA_H
