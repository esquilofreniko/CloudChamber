#include "timing.h"

Timing::Timing() {
    frameRate = 200;
    ofSetFrameRate(frameRate);
    bpm = 100;
}

float Timing::getElapsedTime() {
    return elapsedTime;
}

void Timing::update() {
    elapsedTime = ofGetElapsedTimef();
}


void Timing::displayData() {
    int x = 10;
    int y = 15;
    int ySpacing = 15;
    ofDisableLighting();
    ofSetColor(255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), x, y);
}
