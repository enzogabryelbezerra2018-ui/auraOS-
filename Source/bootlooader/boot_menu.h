#ifndef BOOT_MENU_H
#define BOOT_MENU_H

#include <vector>
#include <string>

class BootMenu {
public:
    BootMenu(const std::vector<std::string>& items);
    void run(); // Exibe e interage com o menu
private:
    std::vector<std::string> menu_items;
    int selected_index;
    void render();
    void move_up();
    void move_down();
};

#endif
