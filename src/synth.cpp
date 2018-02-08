#include "synth.h"

Synth::Synth() {

}

void Synth::modulate(std::string param, float value) {
    synth[currentVoice]->set(param, value);
}

void Synth::play(float freq, float amp) {
    /*
    if (currentVoice == numVoices) {
        currentVoice = 0;
     }
     */

    currentVoice %= numVoices-1;
    synth[currentVoice]->set("freq", freq);
    synth[currentVoice]->set("amp", amp);
    synth[currentVoice]->create();
    ++currentVoice;
}
