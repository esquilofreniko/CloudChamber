#include "instruments.h"

Fm::Fm() {
	f = 80;
	a = 1;
	ratio = 1.3;
	index = 300;
}

double Fm::output() {
	return a * (carrier.sinewave(f + (index * modulator.sinewave(f * ratio))));
}
