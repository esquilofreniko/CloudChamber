#include "timing.h"

Timing::Timing() {
    frameRate = 200;
    ofSetFrameRate(frameRate);
    bpm = 100;
}

void Timing::update() {
    elapsedTime = ofGetElapsedTimef();
}

float Timing::getElapsedTime() {
    return elapsedTime;
}

void Timing::generateRandom() {
    for (int i = 0; i < 32; ++i) {

        
    }
    
}

void Timing::displayData() {
    int x = 10;
    int y = 15;
    int ySpacing = 15;
    ofDisableLighting();
    ofSetColor(255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), x, y);
}
