#include "nfc_types.h"
#include <stdio.h>
#include <vector>

// Função para escanear tags NFC
std::vector<NFCTag> scan_nfc_tags(){
    std::vector<NFCTag> tags;

    // Simulação de uma tag encontrada
    NFCTag tag;
    tag.type = NFCTagType::NDEF;
    tag.uid = "04A2243B7C";
    tag.data = "Hello AuraOS NFC!";
    tags.push_back(tag);

    printf("Scanned %d NFC tags\n", (int)tags.size());
    return tags;
}

// Função para imprimir informações da tag
void print_nfc_tag(NFCTag &tag){
    printf("NFC Tag UID: %s\n", tag.uid.c_str());
    printf("Type: %d\n", (int)tag.type);
    printf("Data: %s\n", tag.data.c_str());
}
