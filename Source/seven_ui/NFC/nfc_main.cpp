#include "nfc_reader.cpp"
#include "nfc_writer.cpp"
#include "nfc_types.h"
#include <stdio.h>
#include <unistd.h>

// Loop principal do NFC
void nfc_loop(){
    while(true){
        auto tags = scan_nfc_tags();
        for(auto &tag : tags){
            print_nfc_tag(tag);
            write_nfc_tag(tag, "AuraOS updated!");
        }
        usleep(2000000); // espera 2 segundos antes de escanear novamente
    }
}

// Função para iniciar o NFC manualmente
void start_nfc(){
    printf("Starting NFC module...\n");
    nfc_loop();
}
