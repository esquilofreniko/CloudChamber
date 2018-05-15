#ifndef instruments_h
#define instruments_h

#include "ofxMaxim.h"

struct Fm {
	public:
	Fm();
	maxiOsc carrier;
	double f, a, index;
	double output(double modulator);
};

#endif /* instruments_h */
