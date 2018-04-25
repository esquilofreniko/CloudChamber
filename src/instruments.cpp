#include "instruments.h"

double Partial::play(double f, double a) {
	return a * partial.sinewave(f);
}

double Fm::play(double f, double a, double ratio, double index) {
	double wave = a * carrier.sinewave(f + (index * modulator.sinewave(f * ratio)));
	return wave;
}
