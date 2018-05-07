#ifndef instruments_h
#define instruments_h

#include "ofxMaxim.h"

class Fm {
	public:
	Fm();
	maxiOsc carrier, modulator;
	double f;
	double a;
	double ratio;
	double index;
	double output();
};

#endif /* instruments_h */
