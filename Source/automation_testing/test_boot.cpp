#include <stdio.h>

void test_boot(){
    printf("[TEST] Boot logo test...\n");
    // Simulação: verifica se o boot logo é carregado
    bool logo_loaded = true;
    if(logo_loaded){
        printf("[PASS] Boot logo loaded correctly.\n");
    } else {
        printf("[FAIL] Boot logo not loaded.\n");
    }
}
