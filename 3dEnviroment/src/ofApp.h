#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofCamera cam;
		ofVec3f campos;
		ofPlanePrimitive plane1;
		ofPlanePrimitive plane2;
		ofPlanePrimitive plane3;
		ofPlanePrimitive plane4;
		ofPlanePrimitive plane5;
		ofPlanePrimitive plane6;

		int numcols = 100;
		int numrows = 100;
		int height = 100;
		int camx = 0;
		int camy = 0;
		int camz = 10;
};
