#include "boot_animations.h"
#include "boot_display.h"
#include <thread>
#include <chrono>
#include <iostream>

void fade_in_screen(int duration_ms) {
    for(int i = 0; i <= 255; i+=15) {
        clear_screen();
        // Simula fade com cor de fundo crescente
        std::cout << "\033[48;2;" << i << ";" << i << ";" << i << "m";
        std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms / 17));
    }
    std::cout << "\033[0m";
}

void fade_out_screen(int duration_ms) {
    for(int i = 255; i >= 0; i-=15) {
        clear_screen();
        std::cout << "\033[48;2;" << i << ";" << i << ";" << i << "m";
        std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms / 17));
    }
    std::cout << "\033[0m";
}

void animate_arrow(int x, int y, int repeat) {
    for(int i=0;i<repeat;i++){
        draw_arrow(x, y);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        draw_text(x, y, " ", HIGHLIGHT_COLOR); // Apaga seta
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
