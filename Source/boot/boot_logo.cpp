#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "stb_image.h"

// Framebuffer
struct FrameBuffer {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
};

// UI do Boot
struct BootUI {
    int logo_x;
    int logo_y;
    int logo_width;
    int logo_height;
    float alpha;
    float scale;        // escala do logo para zoom
    int text_x;
    int text_y;
};

// Paleta de cores psicodélica
uint32_t colors[] = {
    0xFFFF0000, 0xFFFF7F00, 0xFFFFFF00, 0xFF00FF00,
    0xFF00FFFF, 0xFF0000FF, 0xFFFF00FF, 0xFFFFFFFF
};
#define COLORS_COUNT (sizeof(colors)/sizeof(uint32_t))

// Inicializa UI
void init_boot_ui(BootUI &ui, FrameBuffer *fb, int logo_width, int logo_height) {
    ui.logo_width = logo_width;
    ui.logo_height = logo_height;
    ui.logo_x = (fb->width - logo_width) / 2;
    ui.logo_y = (fb->height - logo_height) / 2;
    ui.alpha = 0.0f;
    ui.scale = 1.0f;
    ui.text_x = fb->width / 2;
    ui.text_y = fb->height / 4;
}

// Desenha fundo psicodélico animado
void draw_background(FrameBuffer *fb, int frame) {
    for (uint32_t y = 0; y < fb->height; y++) {
        for (uint32_t x = 0; x < fb->width; x++) {
            uint32_t color_index = (x + y + frame) % COLORS_COUNT;
            fb->pixels[y * fb->width + x] = colors[color_index];
        }
    }
}

// Desenha logo centralizado com escala e alfa
void draw_logo(FrameBuffer *fb, stbi_uc *img, BootUI &ui) {
    int scaled_width = (int)(ui.logo_width * ui.scale);
    int scaled_height = (int)(ui.logo_height * ui.scale);
    int start_x = (fb->width - scaled_width) / 2;
    int start_y = (fb->height - scaled_height) / 2;

    for (int y = 0; y < scaled_height; y++) {
        for (int x = 0; x < scaled_width; x++) {
            int src_x = x * ui.logo_width / scaled_width;
            int src_y = y * ui.logo_height / scaled_height;
            int fb_index = (start_y + y) * fb->width + (start_x + x);
            int img_index = (src_y * ui.logo_width + src_x) * 4;

            uint8_t r = img[img_index];
            uint8_t g = img[img_index + 1];
            uint8_t b = img[img_index + 2];
            uint8_t a = (uint8_t)(img[img_index + 3] * ui.alpha);

            if (a > 0) {
                fb->pixels[fb_index] = (a << 24) | (r << 16) | (g << 8) | b;
            }
        }
    }
}

// Desenha mensagem de boot flutuante
void draw_boot_text(FrameBuffer *fb, const char *text, BootUI &ui) {
    // Implementação simplificada: apenas exibe no console
    printf("BOOT MESSAGE: %s\n", text);
}

// Função principal do boot animado
void boot_logo_main(FrameBuffer *fb) {
    stbi_image *img = stbi_load("logo.png");
    if (!img) {
        printf("Erro: logo.png não encontrado.\n");
        return;
    }

    BootUI ui;
    init_boot_ui(ui, fb, img->width, img->height);

    int frame = 0;
    while (frame < 200) { // loop de boot (200 frames)
        draw_background(fb, frame);

        // Efeito fade-in do logo
        if (frame < 50) ui.alpha = frame / 50.0f;
        else ui.alpha = 1.0f;

        // Efeito de pulso / zoom
        ui.scale = 1.0f + 0.05f * sin(frame * 0.1f);

        draw_logo(fb, img->data, ui);

        // Mensagem flutuante
        draw_boot_text(fb, "AuraOS - Booting...", ui);

        usleep(50000); // 20 FPS
        frame++;
    }

    stbi_image_free(img);
}
