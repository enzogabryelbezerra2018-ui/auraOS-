#include <stdio.h>
#include <string>

void play_audio_simulation(const std::string &text, float speed, float pitch){
    // Simula a reprodução de áudio TTS
    printf("[AudioSim] Playing '%s' at speed %.2f pitch %.2f\n", text.c_str(), speed, pitch);
}

void stop_audio_simulation(){
    printf("[AudioSim] Audio stopped\n");
}
