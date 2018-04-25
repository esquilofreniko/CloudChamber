#include "ofApp.h"

namespace synths {
	vector<Partial> partials(32);
	vector<Fm> fmSynth(32);
}

void ofApp::setup() {
    ofEnableLighting();
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetSmoothLighting(true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(30, 30, 30);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    light.setup();
    light.setPointLight();
    light.setPosition(0, 0, 0);
    light.setAttenuation(1, (0.000001), (0.000001));
    mesh[0].init(-width / 4, -height / 4, -depth / 4, width / 4, height / 4, depth / 4);
    model[0].init("heart.obj", 1);
    for(int i = 0; i < 4; i++)
        attractor[i].init(width, height, depth);

	ofSoundStreamSetup(2, 2, this, sampleRate, bufferSize, 4);
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
	
	for (int i = 0; i < bufferSize; ++i) {
		
		double mix = 0;
		mix += synths::fmSynth[0].play(100, 0.25, 1.3, 200);
		
		output[i*nChannels]     = 	mix;
		output[i*nChannels + 1] =	output[i*nChannels];
		
	}

}



void ofApp::structure() {
    int frame = timing.getFrame();
    int frameNum = 2000; // temporary: still need to implement a better way of sequencing the state changes
    if (frame % frameNum == 0)
        states.changeState();
    switch (states.getCurrent()) {
        case 1:
            light.enable();
            if (frame % 4000 == 0)
                points[0].init(width,height,depth);
            break;
        case 2:
            light.disable();
            numattractors = 1;
            attractor[0].f = 2;
            attractor[0].pos.set(0,0,0);
            break;
        case 3:
            attractor[0].f = -2;
            if (frame % 4000 == 0) {
                points[0].stop();
            }
            break;
        case 4:
            model[0].active = true;
            break;
        case 5:
             if (frame % 4000 == 0) {
                points[0].stop();
                numattractors = 3;
                attractor[0].f = 2;
                attractor[1].f = -2;
                attractor[2].f = 4;
            }
            break;
        case 6:
            lines[0].active = true;
            if (model[0].vertexcounter == 0) {
                model[0].active = false;
            }
            break;
        case 7:
            if (model[0].vertexcounter == 0) {
                model[0].active = false;
            }
            break;
        case 8:
            if (frame % 4000 == 0) {
                numattractors = 2;
                attractor[0].f = 4;
                attractor[1].f = 2;
                points[0].stop();
            }
            break;
        default:
            break;
    }
}

void ofApp::update() {

    structure(); // call the function that determines the state changes over time

    for (int i = 0; i < 4; ++i) {
        attractor[i].light.disable();
    }
    
    if(timing.getFrame() % 800 == 0) {
        lines[0].clear(width, height, depth, 5);
    }
    
    lines[0].update(width,height,depth,4);
    points[0].update(width,height,depth);
    model[0].render(0,-height/16,0,2,175,5);
    for(int i = 0; i < numattractors; ++i) {
		attractor[i].limit(width,height,depth);
        attractor[i].lighton();
        attractor[i].update(25);
        points[0].attracted(attractor[i].pos,attractor[i].f,numattractors);
        for(int j = 0; j <= numattractors; j++)
		    if (j != i)
				attractor[j].attracted(attractor[i].pos,attractor[i].f,numattractors);
        }
	}

void ofApp::draw(){
    space.cam.begin();
    space.drawBackground(0, 25);
    space.drawWireframe(8, 25);
    points[0].draw(250, 250, granprob);
    for (int i = 0; i < numattractors; ++i)
        attractor[i].draw(10,5);
    lines[0].draw(0, 0, 255, 25);
    model[0].draw(250, 50, 180, 180, 0.01);
    space.cam.end();
    timing.displayData();
}

void ofApp::keyPressed(int key){
	
	space.movecam(key);
	
	switch (key) {
		case '1':
		    space.framedraw = !space.framedraw;
			break;
		case '2':
			for(int i = 0; i < 4; i++)
				attractor[i].attract = !attractor[i].attract;
			break;
		case 'r':
			points[0].stop();
			for(int i = 0; i < numattractors; i++) {
				attractor[i].init(width, height, depth);
				if(i == 0)
					attractor[0].pos.set(0,0,0);
				ofBackground(0);
			}
			break;
		case ' ':
			numattractors += 1;
			numattractors = numattractors % 5;
			points[0].stop();
			for(int i = 0; i < numattractors; i++) {
				attractor[i].init(width,height,depth);
				if(i == 0) attractor[0].pos.set(0,0,0);
			}
			ofBackground(0);
			break;
		case 'f':
			ofToggleFullscreen();
			break;
		default:
			break;
	}
}
			

/*
void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){

}
*/
