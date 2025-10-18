#include <stdint.h>
#include <stdio.h>
#include <unistd.h> // apenas para sleep em segundos (em emulador)
#include "colors.c"

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} FrameBuffer;

// Desenha efeito animado de cores no framebuffer
void draw_animated_colors(FrameBuffer *fb, int frame) {
    for (uint32_t y = 0; y < fb->height; y++) {
        for (uint32_t x = 0; x < fb->width; x++) {
            // Alterna cores dependendo do frame
            uint32_t color_index = (x + y + frame) % PANIC_COLORS_COUNT;
            fb->pixels[y * fb->width + x] = panic_colors[color_index];
        }
    }
}

// Função principal do kernel panic animado
void kernel_panic(FrameBuffer *fb, const char *message, int do_reboot) {
    printf("KERNEL PANIC: %s\n", message);

    int frame = 0;
    while (1) {
        draw_animated_colors(fb, frame);
        frame++;

        // Pequeno delay (ajustável)
        usleep(50000); // 50ms = 20 FPS

        if (do_reboot) {
            extern void system_reboot();
            system_reboot();
        }
    }
}
