#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdint.h>

void vga_init();
void vga_put_char(char c, int x, int y, uint8_t color);

void keyboard_init();
void timer_init();

#endif
