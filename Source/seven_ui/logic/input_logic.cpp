#include "../seven_ui.h"
#include <stdio.h>

// Funções de input simuladas, podem ser adaptadas para hardware real
bool is_power_button_pressed() { return false; }
bool is_volume_down_pressed() { return false; }
bool is_volume_up_pressed() { return false; }

void handle_input(SevenUI &ui){
    if(is_volume_down_pressed()) ui.navigate(1);
    if(is_volume_up_pressed()) ui.navigate(-1);
    if(is_power_button_pressed()) ui.click_selected();
}
