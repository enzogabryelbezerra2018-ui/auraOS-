#ifndef PICO_TTS_H
#define PICO_TTS_H

#include <string>

struct PicoTTSConfig {
    float speed;    // velocidade da fala
    float pitch;    // tom da voz
};

class PicoTTS {
public:
    PicoTTSConfig config;

    PicoTTS();
    void say(const std::string &text);
    void stop();
    void set_speed(float speed);
    void set_pitch(float pitch);
};

#endif
