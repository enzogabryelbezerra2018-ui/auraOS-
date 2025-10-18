#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "stb_image.h"
#include "font.h"

// Framebuffer
struct FrameBuffer {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
};

// UI do Boot
struct BootUI {
    int logo_x, logo_y;
    int logo_width, logo_height;
    float alpha;
    float scale;
    int text_x, text_y;
};

// Paleta psicodélica (Boot + Panic)
uint32_t colors[] = {
    0xFFFF0000,0xFFFF7F00,0xFFFFFF00,0xFF00FF00,
    0xFF00FFFF,0xFF0000FF,0xFFFF00FF,0xFFFFFFFF
};
#define COLORS_COUNT (sizeof(colors)/sizeof(uint32_t))

void draw_background(FrameBuffer *fb, int frame) {
    for(uint32_t y=0;y<fb->height;y++){
        for(uint32_t x=0;x<fb->width;x++){
            uint32_t idx = (x+y+frame)%COLORS_COUNT;
            fb->pixels[y*fb->width + x] = colors[idx];
        }
    }
}

// Inicializa UI do Boot
void init_boot_ui(BootUI &ui, FrameBuffer *fb, int logo_w, int logo_h){
    ui.logo_width = logo_w;
    ui.logo_height = logo_h;
    ui.logo_x = (fb->width - logo_w)/2;
    ui.logo_y = (fb->height - logo_h)/2;
    ui.alpha = 0.0f;
    ui.scale = 1.0f;
    ui.text_x = fb->width/2;
    ui.text_y = fb->height - 50;
}

// Desenha logo animado
void draw_logo(FrameBuffer *fb, stbi_uc *img, BootUI &ui){
    int scaled_w = (int)(ui.logo_width*ui.scale);
    int scaled_h = (int)(ui.logo_height*ui.scale);
    int start_x = ui.logo_x + (int)(10*sin(ui.scale*5));
    int start_y = ui.logo_y;

    for(int y=0;y<scaled_h;y++){
        for(int x=0;x<scaled_w;x++){
            int src_x = x*ui.logo_width/scaled_w;
            int src_y = y*ui.logo_height/scaled_h;
            int fb_idx = (start_y+y)*fb->width + (start_x+x);
            int img_idx = (src_y*ui.logo_width + src_x)*4;
            if(fb_idx >= fb->width*fb->height) continue;

            uint8_t r = img[img_idx];
            uint8_t g = img[img_idx+1];
            uint8_t b = img[img_idx+2];
            uint8_t a = (uint8_t)(img[img_idx+3]*ui.alpha);

            if(a>0) fb->pixels[fb_idx] = (a<<24)|(r<<16)|(g<<8)|b;
        }
    }
}

// Renderiza texto bitmap 8x8
void draw_text(FrameBuffer *fb, const char *text, int x, int y, uint32_t color){
    while(*text){
        char c = *text;
        if(c<32||c>126){ text++; continue; }
        for(int row=0;row<8;row++){
            uint8_t bits = font8x8_basic[c-32][row];
            for(int col=0;col<8;col++){
                int px = x+col;
                int py = y+row;
                if(px<fb->width && py<fb->height)
                    fb->pixels[py*fb->width + px] = color;
            }
        }
        x+=8;
        text++;
    }
}

// Kernel Panic animado
void kernel_panic(FrameBuffer *fb, const char *message){
    int frame = 0;
    while(1){
        draw_background(fb, frame);
        draw_text(fb, message, fb->width/2 - 80, fb->height/2, 0xFFFFFFFF);
        frame++;
        usleep(50000); // 20 FPS
    }
}

// Boot animado principal com transição para Panic
void boot_main(FrameBuffer *fb, int simulate_error){
    stbi_image *img = stbi_load("logo.png");
    if(!img){
        kernel_panic(fb, "KERNEL PANIC: logo.png não encontrado!");
        return;
    }

    BootUI ui;
    init_boot_ui(ui, fb, img->width, img->height);

    for(int frame=0; frame<300; frame++){
        draw_background(fb, frame);

        if(frame<50) ui.alpha = frame/50.0f; else ui.alpha = 1.0f;
        ui.scale = 1.0f + 0.05f*sin(frame*0.1f);

        draw_logo(fb, img->data, ui);

        int text_y = ui.text_y + (int)(5*sin(frame*0.1f));
        draw_text(fb, "AuraOS - Booting...", ui.text_x - 60, text_y, 0xFFFFFFFF);

        usleep(40000); // 25 FPS

        if(simulate_error && frame==150){ // Simula erro crítico
            stbi_image_free(img);
            kernel_panic(fb, "KERNEL PANIC: Erro crítico detectado!");
            return;
        }
    }

    stbi_image_free(img);
}
