#ifndef mixer_h
#define mixer_h

#include <vector>
#include <cmath>

class Mixer {
public:
	Mixer();
	void assign(int index, double signal);
	void setLevel(int index, double amount);
	double output();
private:
	int numOutputs;
	std::vector<double> levels;
	std::vector<double> outputs;
};

#endif /* mixer_h */
