#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // usleep
#include "stb_image.h"

// Framebuffer simplificado
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} FrameBuffer;

// Variáveis de UI
typedef struct {
    int logo_x;
    int logo_y;
    int logo_width;
    int logo_height;
    float alpha;      // Transparência (0.0 a 1.0)
} BootUI;

// Paleta de cores animadas
uint32_t colors[] = {
    0xFFFF0000, 0xFFFF7F00, 0xFFFFFF00, 0xFF00FF00,
    0xFF00FFFF, 0xFF0000FF, 0xFFFF00FF, 0xFFFFFFFF
};
#define COLORS_COUNT (sizeof(colors)/sizeof(uint32_t))

// Inicializa variáveis da UI
void init_boot_ui(BootUI *ui, FrameBuffer *fb, int logo_width, int logo_height) {
    ui->logo_width = logo_width;
    ui->logo_height = logo_height;
    ui->logo_x = (fb->width - logo_width) / 2;
    ui->logo_y = (fb->height - logo_height) / 2;
    ui->alpha = 0.0f; // começa transparente para efeito fade-in
}

// Desenha fundo animado
void draw_background(FrameBuffer *fb, int frame) {
    for (uint32_t y = 0; y < fb->height; y++) {
        for (uint32_t x = 0; x < fb->width; x++) {
            uint32_t color_index = (x + y + frame) % COLORS_COUNT;
            fb->pixels[y * fb->width + x] = colors[color_index];
        }
    }
}

// Desenha logo no centro com transparência da UI
void draw_logo_ui(FrameBuffer *fb, stbi_uc *img, BootUI *ui) {
    for (int y = 0; y < ui->logo_height; y++) {
        for (int x = 0; x < ui->logo_width; x++) {
            int fb_index = (ui->logo_y + y) * fb->width + (ui->logo_x + x);
            int img_index = (y * ui->logo_width + x) * 4; // RGBA

            uint8_t r = img[img_index];
            uint8_t g = img[img_index + 1];
            uint8_t b = img[img_index + 2];
            uint8_t a = (uint8_t)(img[img_index + 3] * ui->alpha);

            if (a > 0) {
                fb->pixels[fb_index] = (a << 24) | (r << 16) | (g << 8) | b;
            }
        }
    }
}

// Função principal do boot animado
void boot_logo_main(FrameBuffer *fb) {
    stbi_image *img = stbi_load("logo.png");
    if (!img) {
        printf("Erro: logo.png não encontrado.\n");
        return;
    }

    BootUI ui;
    init_boot_ui(&ui, fb, img->width, img->height);

    // Loop de animação
    for (int frame = 0; frame < 100; frame++) {
        draw_background(fb, frame);

        // Fade-in do logo
        ui.alpha = (frame < 50) ? (frame / 50.0f) : 1.0f;

        draw_logo_ui(fb, img->data, &ui);

        usleep(50000); // 20 FPS
    }

    stbi_image_free(img);
}
