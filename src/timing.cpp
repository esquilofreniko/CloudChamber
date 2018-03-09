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

int Timing::MsToFrame(int ms) {
    return (ms / 1000) / (1.0 / frameRate);
}

void Timing::generateSequence() {
    timeSequence = {500, 2000, 3000, 4000};
}

bool Timing::getTrigger() {
    if (trigger == true) {
        return true;
    } else {
        return false;
    }
}

void Timing::playSequence() {
    int maxFrames = MsToFrame(std::accumulate(timeSequence.begin(), timeSequence.end(), 0));
    int currentFrame = ofGetFrameNum() % maxFrames;
    int currentTime = frameToMs(currentFrame);
    std::cout << currentTime << '\n';
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
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), x, y); // display frame rate
    ofDrawBitmapString("time: "+ofToString(frameToMs(ofGetFrameNum())/1000.0, 2), x, y + (ySpacing)); // display current frame number
}
