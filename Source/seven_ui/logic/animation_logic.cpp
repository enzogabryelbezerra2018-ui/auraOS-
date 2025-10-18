#include "../seven_ui.h"
#include <stdio.h>
#include <unistd.h>

void animate_widget(Widget &w){
    printf("Animating widget %s\n", w.text.c_str());
}

void animate_ui(SevenUI &ui){
    for(int i=0;i<ui.widgets.size();i++){
        animate_widget(ui.widgets[i]);
    }
}
