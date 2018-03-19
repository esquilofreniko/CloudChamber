#include "timing.h"

Timing::Timing() {
    frameRate = 200;
    ofSetFrameRate(frameRate);
    accumulatedTimes = 0;
    timeSequenceIndex = 0;
}

int Timing::frameToMs(int frame) {
    return ((1.0 / frameRate) * frame) * 1000;
}

int Timing::frameToS(int frame){
    return ((1.0 / frameRate) * frame);
}

int Timing::MsToFrame(int ms) {
    return (ms / 1000) / (1.0 / frameRate);
}

void Timing::addToSequence(float f) {
    timeSequence.push_back(f);
}

float Timing::getSequence(int i) {
    return timeSequence[i];
}

bool Timing::getTrigger() {
    if (trigger == true) {
        return true;
    } else {
        return false;
    }
}

int Timing::getNow(){
  return frameToS(ofGetFrameNum());
}

void Timing::playSequence() {
    int maxFrames = MsToFrame(std::accumulate(timeSequence.begin(), timeSequence.end(), 0));
    int currentFrame = ofGetFrameNum() % maxFrames;
    int currentTime = frameToMs(currentFrame);
    if (currentTime >= accumulatedTimes && currentTime <= (accumulatedTimes + frameToMs(1)) ) {
        trigger = true;
        accumulatedTimes += timeSequence[timeSequenceIndex];
        timeSequenceIndex = (timeSequenceIndex + 1) % timeSequence.size();
    } else {
        trigger = false;
    }
}

void Timing::displayData() {
    int x = 10;
    int y = 15;
    int ySpacing = 15;
    ofDisableLighting();
    ofSetColor(255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), x, y); // display frame rate
}
