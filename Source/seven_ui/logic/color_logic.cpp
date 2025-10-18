#include "../seven_ui.h"
#include <stdint.h>
#include <stdio.h>

// Função para gerar cores RGB full
uint32_t rgb(uint8_t r, uint8_t g, uint8_t b){
    return (0xFF<<24) | (r<<16) | (g<<8) | b;
}

// Função psicodélica (ciclo de cores)
uint32_t psychedelic_color(int step){
    uint8_t r = (step*5)%256;
    uint8_t g = (step*3)%256;
    uint8_t b = (step*7)%256;
    return rgb(r,g,b);
}
