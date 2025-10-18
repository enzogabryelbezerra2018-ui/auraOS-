#include "nfc_types.h"
#include <stdio.h>

// Função para escrever dados na tag NFC
bool write_nfc_tag(NFCTag &tag, const std::string &data){
    tag.data = data;
    printf("Writing data to NFC Tag UID %s: %s\n", tag.uid.c_str(), data.c_str());
    return true; // simula sucesso
}
