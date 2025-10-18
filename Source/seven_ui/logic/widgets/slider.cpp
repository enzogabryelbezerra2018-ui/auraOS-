#include "../../seven_ui.h"
#include <stdio.h>

void slider_draw(Widget &w){
    printf("Drawing Slider '%s' at (%d,%d) size %dx%d\n", w.text.c_str(), w.x, w.y, w.w, w.h);
}

void slider_set_value(Widget &w, int value){
    printf("Slider '%s' set to %d\n", w.text.c_str(), value);
}
