#include <stdio.h>
#include "../NFC/nfc_reader.cpp"
#include "../NFC/nfc_writer.cpp"

void test_nfc(){
    printf("[TEST] NFC test...\n");
    auto tags = scan_nfc_tags();
    if(tags.size() > 0){
        printf("[PASS] NFC scan detected %d tags.\n", (int)tags.size());
        write_nfc_tag(tags[0], "AuraOS Test");
    } else {
        printf("[FAIL] No NFC tags detected.\n");
    }
}
