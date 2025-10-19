#include "internet_ui.h"
#include "seven_ui.h"
#include <vector>
#include "html_logic.h"

static int scroll_y = 0;
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16

void html_draw() {
    int cur_y = -scroll_y;
    const std::vector<HtmlChar>& buf = get_html_buffer();

    int cur_x = 0;
    for(size_t i=0;i<buf.size();i++){
        if(buf[i].ch=='\n'){
            cur_x = 0;
            cur_y += CHAR_HEIGHT;
            continue;
        }
        if(cur_y>=0 && cur_y<240){ // dentro da tela
            seven_ui_draw_char(buf[i].ch, cur_x, cur_y, buf[i].color);
        }
        cur_x+=CHAR_WIDTH;
        if(cur_x+CHAR_WIDTH>320){
            cur_x=0;
            cur_y+=CHAR_HEIGHT;
        }
    }
}

void html_scroll(int dy){
    scroll_y+=dy;
    if(scroll_y<0) scroll_y=0;
}

void draw_browser_ui() {
    draw_address_bar();
    draw_navigation_buttons();
    html_draw();
}
