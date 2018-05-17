#include "mixer.h"

Mixer::Mixer() {
	numOutputs = 32;
	for (int i = 0; i < numOutputs; ++i) {
		outputs.push_back(0);
		levels.push_back(1.0 / numOutputs);
	}
}

void Mixer::assign(int index, double signal)  {
	outputs[index] = signal * levels[index];
}

void Mixer::setLevel(int index, double amount) {
	levels[index] = amount;
}

double Mixer::output() {
	double sum = 0;
	for (double d : outputs) sum += d;
	return tanh(sum);
}

