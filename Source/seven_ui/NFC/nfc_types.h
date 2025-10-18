#ifndef NFC_TYPES_H
#define NFC_TYPES_H

#include <stdint.h>
#include <string>

enum class NFCTagType {
    UNKNOWN,
    NDEF,
    MIFARE,
    ISO14443A,
    ISO14443B
};

struct NFCTag {
    NFCTagType type;
    std::string uid;
    std::string data;
};

#endif
