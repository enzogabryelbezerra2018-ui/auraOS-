#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stb_image.h" // Versão simplificada que criamos

// Estrutura simplificada de framebuffer
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} FrameBuffer;

// Desenha a imagem no centro do framebuffer
void draw_image_center(FrameBuffer *fb, stbi_uc *img, int img_width, int img_height) {
    int start_x = (fb->width - img_width) / 2;
    int start_y = (fb->height - img_height) / 2;

    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            int fb_index = (start_y + y) * fb->width + (start_x + x);
            int img_index = (y * img_width + x) * 4; // RGBA

            uint8_t r = img[img_index];
            uint8_t g = img[img_index + 1];
            uint8_t b = img[img_index + 2];
            uint8_t a = img[img_index + 3];

            // Mistura simples de alfa
            if (a > 0) {
                fb->pixels[fb_index] = (a << 24) | (r << 16) | (g << 8) | b;
            }
        }
    }
}

// Função principal de exibição do logo
void boot_logo_main(FrameBuffer *fb) {
    stbi_image *img = stbi_load("logo.png"); // Carrega PNG da mesma pasta
    if (img) {
        draw_image_center(fb, img->data, img->width, img->height);
        stbi_image_free(img);
    } else {
        printf("Erro: logo.png não encontrado ou inválido.\n");
    }
}
