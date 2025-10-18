#include <stdio.h>
#include <stdint.h>

struct FrameBuffer {
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;
};

void init_display(FrameBuffer *fb, int width, int height){
    fb->width = width;
    fb->height = height;
    fb->pixels = new uint32_t[width*height];
    printf("Display initialized: %dx%d\n", width, height);
}

void clear_display(FrameBuffer *fb, uint32_t color){
    for(int i=0;i<fb->width*fb->height;i++){
        fb->pixels[i] = color;
    }
}
