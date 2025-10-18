#include "../../seven_ui.h"
#include <stdio.h>

// Simulação de touch screen
struct TouchEvent {
    int x, y;
    bool pressed;
};

void handle_touch_input(SevenUI &ui, TouchEvent e){
    for(int i=0;i<ui.widgets.size();i++){
        Widget &w = ui.widgets[i];
        if(e.x >= w.x && e.x <= w.x+w.w &&
           e.y >= w.y && e.y <= w.y+w.h &&
           e.pressed){
            if(w.on_click) w.on_click();
        }
    }
}
