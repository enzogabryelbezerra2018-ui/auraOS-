#ifndef BOOT_PALETTE_H
#define BOOT_PALETTE_H

struct RGB {
    int r;
    int g;
    int b;
};

const RGB BG_COLOR = {0,0,0};
const RGB HIGHLIGHT_COLOR = {0,255,255};
const RGB TEXT_COLOR = {255,255,255};

#endif
