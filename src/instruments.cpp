#include "instruments.h"

Fm::Fm() {
	f = 200;
	a = 1;
	index = 1000;
}

double Fm::output(double modulator) {
	return a * (carrier.sinewave(f + (modulator * index)));
}
