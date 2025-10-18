#include "../../seven_ui.h"
#include <stdio.h>

void label_draw(Widget &w){
    printf("Drawing Label '%s' at (%d,%d)\n", w.text.c_str(), w.x, w.y);
}
