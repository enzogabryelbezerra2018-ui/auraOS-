#ifndef SEVEN_UI_H
#define SEVEN_UI_H

#include <stdint.h>
#include <vector>
#include <string>
#include "logic/widget_logic.cpp"
#include "logic/color_logic.cpp"
#include "logic/input_logic.cpp"
#include "logic/menu_logic.cpp"
#include "logic/animation_logic.cpp"

struct FrameBuffer {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
};

struct Widget {
    int x, y, w, h;
    std::string text;
    void (*on_click)();
    uint32_t color_bg;
    uint32_t color_fg;
};

class SevenUI {
public:
    FrameBuffer *fb;
    int width, height;
    std::vector<Widget> widgets;
    int selected_index;

    SevenUI(FrameBuffer *fb);
    void add_widget(Widget w);
    void draw();
    void navigate(int direction);
    void click_selected();
};

#endif
