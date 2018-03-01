#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "wtarray.h"
#include "space.h"
#include "shapes.h"
#include "attractor.h"
#include "clifford.h"
#include "movingAverage.h"
#include "clock.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void play();
    void draw();
    void info();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    int numcols = 400;
    int numrows = 400;
    int height = 400;
    int numattractors = 1;
    int bgreset = 0;
    int bgresetmax = 128;
    int counter = -1;
    float timer = 0;
    float speed = 0.0001;
    ofVec3f randi [1000];

    Attractor attractor[9];
    Space space;
    Points points [4];
    Lines lines [4];
    Shapes shapes [4];
    ofLight light[4];
    Mesh mesh [4];
    Clifford genA;
    MovingAverage avg;
    WtArray wtarray;
    ofxOscReceiver receiver;
};
