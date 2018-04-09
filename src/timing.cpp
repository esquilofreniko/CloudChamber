#include "timing.h"

Timing::Timing() {
    frameRate = 200;
    frameListSize = 8;
    lowerFrame = 1000;
    upperFrame = 8000;
    ofSetFrameRate(frameRate);
    displayColour = 255;
    displayX = 10;
    displayY = 15;
}

void Timing::fillFrameList() {
    for (int i = 0; i < frameListSize; ++i) {
        clifford.iterate();
        int x = map.scale(clifford.getX(i), -1.0, 1.8, lowerFrame, upperFrame); // cast clifford values to int and scale them
        frameList.push_back(x); 
    }
}

int Timing::getListIndex(int i) {
    return frameList[i];
}

int Timing::getFrame() {
    return ofGetFrameNum();
}

void Timing::displayData() {
    ofDisableLighting();
    ofSetColor(displayColour);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), displayX, displayY);
}
