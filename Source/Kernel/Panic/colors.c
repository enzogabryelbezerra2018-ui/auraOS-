#include <stdint.h>

// Paleta de cores "legais" para animação
uint32_t panic_colors[] = {
    0xFFFF0000, // vermelho
    0xFFFF7F00, // laranja
    0xFFFFFF00, // amarelo
    0xFF00FF00, // verde
    0xFF00FFFF, // ciano
    0xFF0000FF, // azul
    0xFFFF00FF, // magenta
    0xFFFFFFFF  // branco
};

#define PANIC_COLORS_COUNT (sizeof(panic_colors)/sizeof(uint32_t))
