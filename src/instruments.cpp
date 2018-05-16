#include "instruments.h"

// Fm
Fm::Fm() {
	f = 200;
	a = 1;
	index = 1000;
}

double Fm::output(double modulator) {
	return a * (carrier.sinewave(f + (modulator * index)));
}

// Bp
Bp::Bp() {
	f1 = 100;
	f2 = 10000;
	q = 1;
}

double Bp::output(double input) {
	double hires = hp.hires(input, f2, q);
	return lp.lores(hires, f1, q);
}

// Perc
Perc::Perc() {
	filterState = true;
	p.useFilter = filterState;
	releaseMin = 20;
	releaseMax = 2000;
	ampMin = 0.1;
	ampMax = 1.0;
	freq = 1000;
}

void Perc::trigger(bool input) {
	if (input) {
		p.setPitch(ofRandom(freq, freq));
		p.setRelease(ofRandom(releaseMin, releaseMax));
		p.cutoff = cutoff;
		p.trigger();
	}
}

double Perc::output() {
	return ofRandom(ampMin, ampMax) * p.play();
}
