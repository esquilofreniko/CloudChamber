#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"
#include "model.h"
#include "wtarray.h"
#include "space.h"
#include "shapes.h"
#include "attractor.h"
#include "clifford.h"
#include "moving_average.h"
#include "counter.h"
#include "random.h"
#include "mapping.h"
#include "osc.h"
#include "rhythm.h"

class ofApp : public ofBaseApp {
    public:
    void setup();
    void update();
    void draw();
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

    int numattractors = 1;
    int bgreset = 0;
    int bgresetmax = 128;
    float timer = 0;
    float speed = 0.001;

    ofVec3f randi [1000];
    Space space;
    Attractor attractor[4];
    Model model[2];
    Points points [4];
    Lines lines [4];
    Shapes shapes [4];
    Mesh mesh [4];
    Clifford clifford;
    MovingAverage avg;
    Random rand;
    Map map;
    Counter counter;
    WtArray wtarray;
    ofxOscReceiver receiver;
    OscSender maxpatch;
    Rhythm rhythm;

    int numcols = space.numcols;
    int numrows = space.numrows;
    int height = space.height;
};
