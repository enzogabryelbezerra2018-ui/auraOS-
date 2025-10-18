#include "test_boot.cpp"
#include "test_seven_ui.cpp"
#include "test_debug_mode.cpp"
#include "test_nfc.cpp"
#include "test_utils.cpp"
#include <stdio.h>

int main(){
    printf("=== AuraOS Automation Testing ===\n");
    test_boot();
    test_seven_ui();
    test_debug_mode();
    test_nfc();
    printf("=== All tests finished ===\n");
    return 0;
}
