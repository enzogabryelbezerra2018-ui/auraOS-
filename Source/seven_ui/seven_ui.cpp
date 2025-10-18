#include "seven_ui.h"
#include <stdio.h>

SevenUI::SevenUI(FrameBuffer *fb){
    this->fb = fb;
    this->width = fb->width;
    this->height = fb->height;
    this->selected_index = 0;
}

void SevenUI::add_widget(Widget w){
    widgets.push_back(w);
}

void SevenUI::draw(){
    printf("Seven UI Drawing %d widgets\n", (int)widgets.size());
    for(int i=0;i<widgets.size();i++){
        Widget &w = widgets[i];
        printf("[%d] Widget: %s at (%d,%d) size %dx%d\n", i, w.text.c_str(), w.x, w.y, w.w, w.h);
    }
}

void SevenUI::navigate(int direction){
    selected_index += direction;
    if(selected_index < 0) selected_index = 0;
    if(selected_index >= widgets.size()) selected_index = widgets.size()-1;
    printf("Selected widget index: %d\n", selected_index);
}

void SevenUI::click_selected(){
    if(selected_index >= 0 && selected_index < widgets.size()){
        Widget &w = widgets[selected_index];
        if(w.on_click) w.on_click();
    }
}
