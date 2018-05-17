#ifndef instruments_h
#define instruments_h

#include "ofxMaxim.h"
#include "ofMain.h"

// FM synthesis modulating a sine wave's frequency with an external source
struct Fm {
	Fm();
	maxiOsc carrier;
	double f, a, index;
	double output(double modulator);
};

// Bandpass filter formed with a lowpass and highpass filter
struct Bp {
	Bp();
	maxiFilter lp, hp;
	double f1, f2, q;
	double output(double input);
};

// High-hat based percussion
struct Perc {
	Perc();
	maxiHats p;
	double freq, cutoff, ampMin, ampMax;
	int releaseMin, releaseMax;
	bool filterState;
	void trigger(bool input);
	double output();
};

// Kick drum
struct Kick {
	Kick();
	maxiKick k;
	int releaseMin, releaseMax;
	bool distortion, filter, limiter;
	double distortionLevel, cutoffMin, cutoffMax, resonanceMin, resonanceMax;
	void trigger(bool input);
	double output();
};

#endif /* instruments_h */
