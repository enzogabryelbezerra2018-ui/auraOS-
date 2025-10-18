#include "../seven_ui.h"
#include <stdio.h>

void sample_widget_action(){
    printf("Widget clicked!\n");
}

void update_widget_color(Widget &w, uint32_t color){
    w.color_bg = color;
}
