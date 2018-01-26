#include "synth.h"

Synth::Synth() {
    
}

void Synth::setup(int setVoices, std::string setName) {
    currentVoice = 0;
    numVoices = setVoices;
    name = setName;
    for(int i = 0; i < numVoices; i++) {
        synth[i] = new ofxSCSynth(name);
    }
}

void Synth::modulate(std::string param, float value) {
    synth[currentVoice]->set(param, value);
}

void Synth::play(float freq, float amp) {
    if (currentVoice == numVoices) {
        currentVoice = 0;
    }
    synth[currentVoice]->set("cfreq", freq);
    synth[currentVoice]->set("amp", amp);
    synth[currentVoice]->create();
    ++currentVoice;
}
