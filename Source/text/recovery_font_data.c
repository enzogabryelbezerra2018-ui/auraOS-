// ===========================================================
//  AuraOS Kernel - Subsistema de Texto
//  Arquivo: Source/text/recovery_font_data.c
//  Autor: Enzo Gabriel Bezerra
//  Descrição: Implementação da fonte bitmap 8x16 (ASCII 32–127)
//  Baseado na fonte VGA original (modo texto BIOS).
// ===========================================================

#include "font_def.h"

// -----------------------------------------------------------------
// Fonte VGA 8x16 padrão (caracteres ASCII 32–127)
// Cada caractere ocupa 16 bytes, cada byte = 8 pixels horizontais.
// Bit = 1 → pixel aceso; Bit = 0 → pixel apagado.
// -----------------------------------------------------------------

const recovery_glyph_t g_recovery_font_data[RECOVERY_FONT_NUM_GLYPHS] = {
    #include "vga8x16_font.inc"
};

// -----------------------------------------------------------------
// Perfil da fonte do sistema Seven UI
// -----------------------------------------------------------------
const SystemFontProfile_t g_seven_ui_font_profile = {
    .family_name       = "Seven Sans",
    .regular_path      = "/system/fonts/seven_sans_regular.ttf",
    .bold_path         = "/system/fonts/seven_sans_bold.ttf",
    .line_height_ratio = 1.25f,
    .antialiasing_mode = AA_MODE_GRAYSCALE,
    .default_color_rgb = 0xFFFFFF
};
