#ifndef BOOT_INPUT_H
#define BOOT_INPUT_H

enum ButtonPress {
    NONE,
    UP,
    DOWN,
    START
};

ButtonPress get_button_press(); // Captura tecla pressionada

#endif
