#ifndef instruments_h
#define instruments_h

#include "ofxMaxim.h"

struct Fm {
public:
	maxiOsc carrier, modulator;
	double play(double f, double a, double ratio, double index);
};

struct Partial {
public:
	maxiOsc partial;
	double play(double f, double a);
};



#endif /* synthesis_h */
