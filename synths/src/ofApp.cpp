#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofBuffer buffer = ofBufferFromFile("info.txt");
    for (auto line : buffer.getLines()) {
        textLines.push_back(line);
    }
    defaultFont.load("arial", 12);
    genA.init(-1.4, 1.6, 1.0, 0.7);
    synthA.setup(16, "fm"); // load synthdef
}


void ofApp::update() {

}

void ofApp::draw() {
    defaultFont.drawString(textLines[0], 20, 20); // output text from file
}

void ofApp::mousePressed(int x, int y, int button) {
    genA.iterate();
    float f = abs(genA.x * 300) + 500; // temporary scaling
    float a = abs(genA.y) * 0.2;       // of generative output
    synthA.play(f, a);
    //synthA.modulate("mindex", f); // does not currently work: must be fixed
    std::cout << "voice: " << synthA.currentVoice << " | frequency: " << f << '\n'; // temporary logging
}
