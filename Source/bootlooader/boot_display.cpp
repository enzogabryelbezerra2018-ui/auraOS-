#include "boot_display.h"
#include <iostream>

void clear_screen() {
    std::cout << "\033[2J\033[1;1H"; // Limpa o console
}

void draw_text(int x, int y, const char* text, RGB color) {
    std::cout << "\033[" << y << ";" << x << "H"; 
    std::cout << "\033[38;2;" << color.r << ";" << color.g << ";" << color.b << "m";
    std::cout << text;
    std::cout << "\033[0m";
}

void draw_button(int x, int y, const char* text, bool highlighted) {
    RGB color = highlighted ? HIGHLIGHT_COLOR : TEXT_COLOR;
    draw_text(x, y, text, color);
}

void draw_arrow(int x, int y) {
    draw_text(x, y, "→", HIGHLIGHT_COLOR);
}
