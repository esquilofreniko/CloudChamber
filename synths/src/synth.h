#ifndef synth_h
#define synth_h

#define MAXVOICES 32
#include "ofMain.h"
#include "ofxSuperCollider.h"

class Synth {
    public:
    void setup(int numVoices, std::string name);
    void play(float freq, float amp);
    void modulate(std::string param, float value);
    int numVoices;
    std::string name;
    int currentVoice;
    ofxSCSynth *synth[MAXVOICES];
    Synth();
};
    
#endif
