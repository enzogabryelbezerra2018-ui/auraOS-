#include "boot_input.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

ButtonPress get_button_press() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    switch(ch) {
        case 'w': return UP;
        case 's': return DOWN;
        case '\n': return START;
        default: return NONE;
    }
}
