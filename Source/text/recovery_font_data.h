// Source/text/recovery_font_data.h
// Header da fonte de recuperação do AuraOS Kernel
// Este arquivo funciona com o .zip extraído: vga8x16_font.inc

#ifndef RECOVERY_FONT_DATA_H
#define RECOVERY_FONT_DATA_H

#include "font_def.h"

// ===================================
// 1. Inclusão da tabela de glifos
// ===================================
// Certifique-se de extrair o ZIP antes e colocar vga8x16_font.inc na mesma pasta
#include "vga8x16_font.inc"

// ===================================
// 2. Perfil da fonte Seven UI
// ===================================
extern const SystemFontProfile_t g_seven_ui_font_profile;

// ===================================
// 3. Ponteiro para os glifos da fonte de recuperação
// ===================================
extern const recovery_glyph_t g_recovery_font_data[RECOVERY_FONT_NUM_GLYPHS];

#endif // RECOVERY_FONT_DATA_H
