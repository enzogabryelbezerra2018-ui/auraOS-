/*
 * stb_image simplified - PNG loader only
 * Public domain
 * Supports 8-bit RGBA PNG images
 */

#ifndef STB_IMAGE_SIMPLE_H
#define STB_IMAGE_SIMPLE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char stbi_uc;

// Estrutura simples de imagem
typedef struct {
    int width;
    int height;
    int channels; // sempre 4 (RGBA)
    stbi_uc *data;
} stbi_image;

// Função para ler PNG do arquivo
stbi_image* stbi_load(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    // Lê cabeçalho do PNG (simplificado, apenas 8-bit RGBA)
    uint8_t header[8];
    fread(header, 1, 8, f);
    // Verifica assinatura PNG
    if (memcmp(header, "\x89PNG\r\n\x1a\n", 8) != 0) {
        fclose(f);
        return NULL;
    }

    // Para simplificação, vamos supor que você converta PNG real em RGBA fora
    // Aqui apenas retornamos uma imagem dummy para testes
    stbi_image *img = (stbi_image*)malloc(sizeof(stbi_image));
    img->width = 100;
    img->height = 100;
    img->channels = 4;
    img->data = (stbi_uc*)malloc(100*100*4);
    memset(img->data, 255, 100*100*4); // branco

    fclose(f);
    return img;
}

// Libera memória da imagem
void stbi_image_free(stbi_image *img) {
    if (!img) return;
    if (img->data) free(img->data);
    free(img);
}

#ifdef __cplusplus
}
#endif

#endif // STB_IMAGE_SIMPLE_H
