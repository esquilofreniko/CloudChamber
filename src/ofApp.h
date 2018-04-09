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
#include "movingAverage.h"
#include "counter.h"
#include "random.h"
#include "osc.h"
#include "timing.h"
#include "states.h"

class ofApp : public ofBaseApp {
public:
    void structure();
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

    int numattractors = 0;
    int bgreset = 0;
    int bgresetmax = 128;
    int granprob = 2;
    int divisionsize = 32;

    ofLight light;
    Space space;
    Attractor attractor[4];
    Model model[2];
    Points points [1];
    Lines lines [1];
    Mesh mesh [4];
    Counter counter;
    Timing timing;
    WtArray wtarray;
    ofxOscReceiver receiver;
    OscSender maxpatch;
    States states;
    Map map;

    int width = space.width;
    int height = space.height;
    int depth = space.depth;
};
