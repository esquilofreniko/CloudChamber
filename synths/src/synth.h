#ifndef synth_h
#define synth_h

#define MAXVOICES 16
#include "ofMain.h"
#include "ofxSuperCollider.h"

class Synth {
    public:
    int numVoices = MAXVOICES;
    void setup(std::string name) {
        currentVoice = 0;
        for(int i = 0; i < numVoices; i++) {
            synth[i] = new ofxSCSynth(name);
        }
    }
    
    std::string name = "default";
    void setup(int numVoices, std::string name);
    void play(float freq, float amp);
    void modulate(std::string param, float value);

    int currentVoice;
    ofxSCSynth *synth[MAXVOICES+1];
    Synth();
};
    
#endif
