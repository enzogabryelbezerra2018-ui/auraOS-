#include "drivers.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
uint16_t* vga_buffer = (uint16_t*)0xB8000;

void vga_init() {
    for(int y=0;y<VGA_HEIGHT;y++)
        for(int x=0;x<VGA_WIDTH;x++)
            vga_buffer[y*VGA_WIDTH + x] = 0x0F20;
}

void vga_put_char(char c, int x, int y, uint8_t color) {
    vga_buffer[y*VGA_WIDTH + x] = ((uint16_t)color<<8)|c;
}
