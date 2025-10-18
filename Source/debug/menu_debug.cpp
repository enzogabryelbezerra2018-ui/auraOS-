#include "menu_debug.h"

struct MenuItem {
    int id;
    const char* text;
    int x, y;
};

struct DebugMenuUI {
    MenuItem items[4];
    int selected_index;
    uint32_t highlight_color;
    float highlight_alpha;
};

// Inicializa menu
void init_menu(DebugMenuUI &menu, int fb_width, int fb_height) {
    menu.items[0] = {1, "Ver logs do sistema", fb_width/10, fb_height/5};
    menu.items[1] = {2, "Testar hardware", fb_width/10, fb_height/5 + 50};
    menu.items[2] = {3, "Status do dispositivo", fb_width/10, fb_height/5 + 100};
    menu.items[3] = {4, "Reiniciar", fb_width/10, fb_height/5 + 150};
    menu.selected_index = 0;
    menu.highlight_color = 0xFF00FFFF; // cor do destaque
    menu.highlight_alpha = 0.5f;
}

// Desenha menu no framebuffer
void draw_menu(FrameBuffer *fb, DebugMenuUI &menu) {
    // Fundo escuro
    for(uint32_t y=0;y<fb->height;y++){
        for(uint32_t x=0;x<fb->width;x++){
            fb->pixels[y*fb->width + x] = 0xFF101010; // cinza escuro
        }
    }

    // Desenha itens
    for(int i=0;i<4;i++){
        int color = (i == menu.selected_index) ? menu.highlight_color : 0xFFFFFFFF;
        draw_text(fb, menu.items[i].text, menu.items[i].x, menu.items[i].y, color);
    }
}

// Move seleção
void move_selection(DebugMenuUI &menu, int direction){
    menu.selected_index += direction;
    if(menu.selected_index < 0) menu.selected_index = 0;
    if(menu.selected_index > 3) menu.selected_index = 3;
}

// Executa ação
void execute_selection(DebugMenuUI &menu){
    int id = menu.items[menu.selected_index].id;
    switch(id){
        case 1: show_logs(); break;
        case 2: test_hardware(); break;
        case 3: show_status(); break;
        case 4: restart_device(); break;
    }
}

// Loop principal do menu gráfico
void menu_loop(FrameBuffer *fb){
    DebugMenuUI menu;
    init_menu(menu, fb->width, fb->height);

    while(1){
        draw_menu(fb, menu);

        if(is_volume_down_pressed()) move_selection(menu, 1);
        if(is_volume_up_pressed()) move_selection(menu, -1);
        if(is_power_button_pressed()) execute_selection(menu);

        usleep(100000); // 10 FPS
    }
}
