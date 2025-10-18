#ifndef MENU_DEBUG_H
#define MENU_DEBUG_H

#include "debug_logs.cpp"

struct FrameBuffer {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
};

bool is_power_button_pressed();
bool is_volume_down_pressed();
bool is_volume_up_pressed();

void draw_text(FrameBuffer *fb, const char* text, int x, int y, uint32_t color);

void menu_loop(FrameBuffer *fb);

#endif
