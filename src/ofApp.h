#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "space.h"
#include "shapes.h"
#include "mapping.h"
#include "attractor.h"
#include "clifford.h"
#include "movingAverage.h"
#include "clock.h"


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    int numcols = 400;
    int numrows = 400;
    int height = 400;
    int numattractors = 1;
    int bgreset = 0;
    int bgresetmax = 128;
    int counter = -1;
    float timer = 0;
    float speed = 0.0001;
    float randx [1000];
    float randy [1000];
    float randz [1000];
    
    ofVec3f wta [4][128];
    Attractor attractor[9];
    Space space;
    Points points [4];
    Lines lines [4];
    Shapes shapes [4];
    ofLight light[4];
    Mesh mesh [4];
    
    Clifford clifford;
    MovingAverage movingAverage;

    int port = 7400;
    ofxOscSender sender;


};
