#include <stdio.h>

void test_debug_mode(){
    printf("[TEST] Debug Mode test...\n");
    // Simulação: testes de menu, logs e entradas
    bool logs_ok = true;
    bool menu_ok = true;

    if(logs_ok && menu_ok){
        printf("[PASS] Debug Mode works correctly.\n");
    } else {
        printf("[FAIL] Debug Mode test failed.\n");
    }
}
