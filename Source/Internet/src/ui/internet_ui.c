#include "internet_ui.h"
#include "seven_ui.h"

void draw_browser_ui() {
    draw_address_bar();
    draw_navigation_buttons();
    draw_html_content(); // chama interpretador Java para retornar pixels/texto
}
