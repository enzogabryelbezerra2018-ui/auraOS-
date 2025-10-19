// Source/text/recovery_font_data.c
// Implementação da fonte de recuperação do AuraOS Kernel
// Funciona tanto com o ZIP original quanto com o arquivo incluído vga8x16_font.inc

#include "recovery_font_data.h"

// ===================================
// 1. Perfil da fonte Seven UI
// ===================================
const SystemFontProfile_t g_seven_ui_font_profile = {
    .family_name = "VGA8x16",
    .regular_path = "Source/text/vga8x16_font.inc", // arquivo incluído para compilação
    .bold_path = NULL,  // Não há versão bold
    .line_height_ratio = 1.0f,
    .antialiasing_mode = AA_MODE_NONE,
    .default_color_rgb = 0xFFFFFF // branco padrão
};

// ===================================
// 2. Ponteiro para os glifos da fonte de recuperação
// ===================================
// Se você extraiu o ZIP, o .inc será incluído aqui
// O kernel acessa os glifos via g_recovery_font_data
const recovery_glyph_t g_recovery_font_data[RECOVERY_FONT_NUM_GLYPHS] = {
    #include "vga8x16_font.inc"
};

// ===================================
// Nota:
// - vga8x16_font.zip contém a versão master da fonte (backup / distribuição)
// - vga8x16_font.inc é extraído do ZIP e usado na compilação
// - Ambos devem estar sincronizados para garantir consistência
