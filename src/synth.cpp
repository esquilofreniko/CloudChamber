#include "synth.h"

Synth::Synth() {

}

void Synth::setup(std::string name) {
    currentVoice = 0;
    for(int i = 0; i < numVoices; i++) {
        synth[i] = new ofxSCSynth(name);
    }
}

// modulate function takes a string argument that corresponds to a parameter of the supercollider synthdef, and a float value corresponding to the parameter itself

void Synth::modulate(std::string param, float value) {
    synth[currentVoice]->set(param, value);
}

// the play function both iterates through a current voice variable, and creates a new instance of the synth for each voice. This isn't ideal as it essentially loads a new copy of the synth within supercollider for each voice. To improve this, we will try to find an approach to polyphony that plays new notes without having to instantiate a new synth

void Synth::play(float freq, float amp) {
    
    currentVoice %= numVoices;
    synth[currentVoice]->create();
    synth[currentVoice]->set("freq", freq);
    synth[currentVoice]->set("amp", amp);
    ++currentVoice;
}
