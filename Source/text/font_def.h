// Source/text/font_def.h
// Definições de estruturas e constantes para o subsistema de texto do AuraOS- Kernel.

#ifndef FONT_DEF_H
#define FONT_DEF_H

#include <stdint.h>
#include <wchar.h> // Essencial para Unicode (wchar_t)

// ===================================
// 1. Configurações da Fonte Bitmap (Modo de Recuperação)
// ===================================

#define RECOVERY_FONT_CHAR_WIDTH    8     // Largura em pixels (fixa)
#define RECOVERY_FONT_CHAR_HEIGHT   16    // Altura em pixels (fixa)
#define RECOVERY_FONT_START_CHAR    32    // Início ASCII (Espaço)
#define RECOVERY_FONT_NUM_GLYPHS    96    // Total de glifos na tabela ASCII (32 a 127)

// Estrutura de um glifo (caractere) para a fonte de recuperação
typedef struct {
    // 16 bytes, onde cada byte representa 8 pixels de uma linha.
    uint8_t bitmap[RECOVERY_FONT_CHAR_HEIGHT]; 
} recovery_glyph_t;

// Declaração da matriz de dados da fonte (implementada em recovery_font_data.c)
extern const recovery_glyph_t g_recovery_font_data[RECOVERY_FONT_NUM_GLYPHS];


// ===================================
// 2. Configurações e Perfil da Seven UI (Renderização de Alto Nível)
// ===================================

// Níveis de Antialiasing (Suavização de Borda)
#define AA_MODE_NONE        0
#define AA_MODE_GRAYSCALE   1
#define AA_MODE_SUBPIXEL    2

// Estrutura do Perfil de Renderização da Fonte Principal
typedef struct {
    const char* family_name;
    const char* regular_path;
    const char* bold_path;
    float line_height_ratio; 
    uint8_t antialiasing_mode; 
    uint32_t default_color_rgb; 
} SystemFontProfile_t;

// Declaração do perfil da Seven UI (implementado em recovery_font_data.c)
extern const SystemFontProfile_t g_seven_ui_font_profile;

#endif // FONT_DEF_H
