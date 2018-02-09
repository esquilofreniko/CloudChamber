#ifndef synth_h
#define synth_h

#define MAXVOICES 16

#include "ofMain.h"
#include "ofxSuperCollider.h"

class Synth {
    public:
    int numVoices = MAXVOICES;
    std::string name = "default";
    void setup(std::string name);
    void play(float freq, float amp);
    void modulate(std::string param, float value);
    int currentVoice;
    ofxSCSynth *synth[MAXVOICES];
    Synth();
};

#endif
