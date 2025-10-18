#include "menu_debug.cpp"
#include <stdio.h>
#include <unistd.h>

bool is_power_button_pressed() { return false; } // Simulação
bool is_volume_down_pressed() { return false; }
bool is_volume_up_pressed() { return false; }

// Função bitmap para desenhar texto
void draw_text(FrameBuffer *fb, const char* text, int x, int y, uint32_t color) {
    // Pode usar font.h para desenhar bitmap real
    printf("DRAW TEXT: %s at (%d,%d)\n", text, x, y);
}

// Função principal do debug mode
void debug_mode_main(FrameBuffer *fb) {
    printf("Entrando no modo Debug...\n");
    menu_loop(fb);
}

// Verifica combinação Power + Volume- (15s)
bool check_debug_mode_pressed() {
    int hold_time = 0;
    while(is_power_button_pressed() && is_volume_down_pressed()){
        usleep(100000);
        hold_time += 100;
        if(hold_time >= 15000) return true;
    }
    return false;
}
