#include "../../seven_ui.h"
#include <stdio.h>

void button_click(Widget &w){
    if(w.on_click) w.on_click();
    printf("Button '%s' clicked!\n", w.text.c_str());
}

void button_draw(Widget &w){
    // Apenas lógica, ainda não desenha no framebuffer
    printf("Drawing Button '%s' at (%d,%d) size %dx%d\n", w.text.c_str(), w.x, w.y, w.w, w.h);
}
