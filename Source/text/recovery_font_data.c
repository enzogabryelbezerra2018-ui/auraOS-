// Source/text/recovery_font_data.c
// Implementação da fonte de recuperação do AuraOS Kernel

#include "font_def.h"

// ===================================
// 1. Inclusão da tabela de glifos
// ===================================
// Se você extraiu o zip, o arquivo deve ser renomeado para "vga8x16_font.inc" 
// ou incluído diretamente do diretório Source/text/
#include "vga8x16_font.inc"

// ===================================
// 2. Perfil da fonte Seven UI
// ===================================
const SystemFontProfile_t g_seven_ui_font_profile = {
    .family_name = "VGA8x16",
    .regular_path = "Source/text/vga8x16_font.inc",
    .bold_path = NULL,  // Não há versão bold neste momento
    .line_height_ratio = 1.0f,
    .antialiasing_mode = AA_MODE_NONE,
    .default_color_rgb = 0xFFFFFF // branco padrão
};

// ===================================
// 3. Ponteiro para os glifos da fonte de recuperação
// ===================================
const recovery_glyph_t g_recovery_font_data[RECOVERY_FONT_NUM_GLYPHS] = {
    // Esta linha inclui todos os 96 glifos ASCII do vga8x16_font.inc
    // Cada glifo é 16 bytes (8x16)
    // A inclusão é feita via arquivo .inc
    #include "vga8x16_font.inc"
};
