#pragma once
#include "ofMain.h"
#include "stuff.h"
#include "clifford.h"
#include "synth.h"
#include "movingAverage.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void info();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int numcols = 100;
		int numrows = 100;
		int height = 100;
		int bgreset = 0;
		int bgresetmax = 128;
		int camx = 0;
		int camy = 0;
		int camz = 10;
		int timerint = 0;
		int otimerint = 1;
		float timer = 0;
		float speed = 0.0001;
		float randx [1000];
		float randy [1000];
		float randz [1000];
    
        int counter;

		ofCamera cam;
		ofVec3f campos;
		ofPlanePrimitive planes [6];
		Points points;
		Lines lines [4];
		Shapes shapes [4];
		ofLight light[4];
		Mesh mesh;

		//audio
        Synth sineDrone;
        Clifford genA;
        MovingAverage avg;
};
