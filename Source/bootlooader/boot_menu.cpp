#include "boot_menu.h"
#include "boot_display.h"
#include "boot_input.h"
#include <thread>
#include <chrono>

BootMenu::BootMenu(const std::vector<std::string>& items)
: menu_items(items), selected_index(0) {}

void BootMenu::render() {
    clear_screen();
    for(size_t i = 0; i < menu_items.size(); i++) {
        bool highlight = (i == selected_index);
        draw_button(5, 2 + i*2, menu_items[i].c_str(), highlight);
        if(highlight) draw_arrow(2, 2 + i*2);
    }
}

void BootMenu::move_up() {
    selected_index--;
    if(selected_index < 0) selected_index = menu_items.size() - 1;
}

void BootMenu::move_down() {
    selected_index++;
    if(selected_index >= (int)menu_items.size()) selected_index = 0;
}

void BootMenu::run() {
    while(true) {
        render();
        ButtonPress btn = get_button_press();
        if(btn == UP) move_up();
        else if(btn == DOWN) move_down();
        else if(btn == START) {
            clear_screen();
            draw_text(5, 5, ("Selecionado: " + menu_items[selected_index]).c_str(), TEXT_COLOR);
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
