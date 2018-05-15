#include "timing.h"

Timing::Timing() {
    frameRate = 200;
    ofSetFrameRate(frameRate);
	displayX = 10;
	displayY = 15;
    displayCol = 255;
}


int Timing::getFrame() {
    return ofGetFrameNum();
}

void Timing::displayData() {
    ofDisableLighting();
    ofSetColor(displayCol);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), displayX, displayY);
}
