#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxMaxim.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"
#include <algorithm>

#include "model.h"
#include "instruments.h"
#include "mixer.h"
#include "space.h"
#include "shapes.h"
#include "attractor.h"
#include "counter.h"
#include "timing.h"
#include "states.h"
#include "wtarray.h"

class ofApp : public ofBaseApp {
    public:
        void structure();
		double wavetable(const int& sample, const int bufferSize);
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
        void gotMessage(ofMessage msg);
        void dragEvent(ofDragInfo dragInfo);

		int initialBufferSize;
		const int sampleRate = 44100;
		const int bufferSize = 512;
		void audioOut(float * output, int bufferSize, int nChannels);
		double outputs[2];
		double mix;

        int numattractors = 0;
        int bgreset = 0;
        int bgresetmax = 128;
        int granprob = 0;
        int divisionsize = 32;
		int bgalpha = 20;

		Fm fm;
		Bp bp;
	    Perc perc;
		Kick kick;
		maxiDistortion dist;
		Mixer mixer;
        ofLight light;
        Space space;
        Attractor attractor[4];
        Model model[2];
        Points points [1];
        Lines lines [1];
        Mesh mesh [4];
        Counter counter;
        Timing timing;
        ofxOscReceiver receiver;
        States states;

		int width = space.width;
		int height = space.height;
		int depth = space.depth;

        WtArray wta;
        maxiOsc osc1;
        maxiOsc osc2;
        maxiDelayline dl1;
	
        maxiKick k1;
        maxiKick s1;
};
