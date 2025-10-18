#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para usleep()
#include "colors.c"
#include "stb_image.h"

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} FrameBuffer;

void draw_animated_colors(FrameBuffer *fb, int frame) {
    for (uint32_t y = 0; y < fb->height; y++) {
        for (uint32_t x = 0; x < fb->width; x++) {
            uint32_t color_index = (x + y + frame) % PANIC_COLORS_COUNT;
            fb->pixels[y * fb->width + x] = panic_colors[color_index];
        }
    }
}

void draw_centered_text(FrameBuffer *fb, const char *text) {
    // Função simplificada para desenhar texto no centro da tela
    // Implementação real dependeria de uma biblioteca gráfica ou código adicional
    printf("Exibindo texto centralizado: %s\n", text);
}

void kernel_panic(FrameBuffer *fb, const char *message, int do_reboot) {
    printf("KERNEL PANIC: %s\n", message);

    int frame = 0;
    while (1) {
        draw_animated_colors(fb, frame);
        draw_centered_text(fb, message);
        frame++;

        usleep(50000); // 50ms = 20 FPS

        if (do_reboot) {
            extern void system_reboot();
            system_reboot();
        }
    }
}
