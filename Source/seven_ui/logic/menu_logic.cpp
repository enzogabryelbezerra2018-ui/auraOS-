#include "../seven_ui.h"
#include "../logic/widget_logic.cpp"
#include <stdio.h>

void create_main_menu(SevenUI &ui){
    Widget w1 = {50,50,200,40,"Boot", sample_widget_action, 0xFF1E90FF, 0xFFFFFFFF};
    Widget w2 = {50,100,200,40,"Debug Mode", sample_widget_action, 0xFF1E90FF, 0xFFFFFFFF};
    Widget w3 = {50,150,200,40,"Kernel Panic", sample_widget_action, 0xFF1E90FF, 0xFFFFFFFF};
    ui.add_widget(w1);
    ui.add_widget(w2);
    ui.add_widget(w3);
}
