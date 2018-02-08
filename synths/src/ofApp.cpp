#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    genA.init(-1.4, 1.6, 1.0, 0.7);
    synthA.setup("sine_drone"); // load synthdef
}

void ofApp::update() {
    genA.iterate();
    avg.update(genA.x[counter]);
    std::cout << counter << "  |  " << genA.x[counter] << '\n';
    ++counter;
    if (counter == 256) {
        counter = 0;
    }
}

void ofApp::draw() {
    
}

void ofApp::mousePressed(int x, int y, int button) {
    genA.iterate();
    //float f = abs(genA.x * 100) + 100; // temporary scaling
    //float a = abs(genA.y) * 0.2;       // of generative output
    float f = ofRandom(400,800);
    float a = ofRandom(0.1, 1);
    synthA.play(f, 0.5);
    std::cout << ofGetMouseX() * 0.01 << '\n';
    std::cout << "voice: " << synthA.currentVoice << " | frequency: " << f << '\n'; // temporary logging
}
