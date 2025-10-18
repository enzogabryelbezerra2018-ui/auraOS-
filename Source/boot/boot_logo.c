#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stb_image.h" // PNG real

// Estrutura de framebuffer
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
} FrameBuffer;

// Variáveis de UI
typedef struct {
    int logo_x;       // Posição X do logo
    int logo_y;       // Posição Y do logo
    int logo_width;   // Largura do logo
    int logo_height;  // Altura do logo
    float alpha;      // Transparência do logo (0.0 a 1.0)
} BootUI;

// Inicializa valores padrões da UI
void init_boot_ui(BootUI *ui, FrameBuffer *fb, int logo_width, int logo_height) {
    ui->logo_width = logo_width;
    ui->logo_height = logo_height;
    ui->logo_x = (fb->width - logo_width) / 2;
    ui->logo_y = (fb->height - logo_height) / 2;
    ui->alpha = 1.0f;
}

// Desenha o logo no framebuffer com variáveis de UI
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

// Função principal de boot
void boot_logo_main(FrameBuffer *fb) {
    stbi_image *img = stbi_load("logo.png");
    if (!img) {
        printf("Erro: logo.png não encontrado ou inválido.\n");
        return;
    }

    BootUI ui;
    init_boot_ui(&ui, fb, img->width, img->height);

    draw_logo_ui(fb, img->data, &ui);

    stbi_image_free(img);
}
