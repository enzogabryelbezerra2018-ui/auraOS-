#ifndef BOOT_DISPLAY_H
#define BOOT_DISPLAY_H

#include "boot_palette.h"

void clear_screen();
void draw_text(int x, int y, const char* text, RGB color);
void draw_button(int x, int y, const char* text, bool highlighted);
void draw_arrow(int x, int y);

#endif
