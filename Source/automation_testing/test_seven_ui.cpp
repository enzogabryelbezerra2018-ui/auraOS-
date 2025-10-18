#include <stdio.h>
#include "../seven_ui/seven_ui.cpp"

void test_seven_ui(){
    printf("[TEST] Seven UI test...\n");

    uint32_t fb_pixels[800*600];
    FrameBuffer fb = {800,600,fb_pixels};

    SevenUI ui(&fb);
    Widget w = {50,50,200,40,"Test Button", nullptr, 0xFF1E90FF, 0xFFFFFFFF};
    ui.add_widget(w);

    ui.draw();
    ui.navigate(1);
    ui.click_selected();

    printf("[PASS] Seven UI logic test completed.\n");
}
