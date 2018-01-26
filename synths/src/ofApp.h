#pragma once

#include "ofMain.h"
#include "clifford.h"
#include "synth.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    void info();
    void mousePressed(int x, int y, int button);
    ofTrueTypeFont defaultFont;
    vector <std::string> textLines;
    std::string text;

    Synth synthA;
    Clifford genA;

};
