#include "pico_tts.h"
#include "pico_audio.cpp"
#include <stdio.h>

PicoTTS::PicoTTS(){
    config.speed = 1.0f;
    config.pitch = 1.0f;
}

void PicoTTS::say(const std::string &text){
    printf("[PicoTTS] Saying: %s\n", text.c_str());
    play_audio_simulation(text, config.speed, config.pitch);
}

void PicoTTS::stop(){
    printf("[PicoTTS] Stopped.\n");
    stop_audio_simulation();
}

void PicoTTS::set_speed(float speed){
    config.speed = speed;
    printf("[PicoTTS] Speed set to %.2f\n", speed);
}

void PicoTTS::set_pitch(float pitch){
    config.pitch = pitch;
    printf("[PicoTTS] Pitch set to %.2f\n", pitch);
}
