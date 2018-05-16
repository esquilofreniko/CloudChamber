#ifndef states_h
#define states_h

#include <iostream>

class States {
public:
	States();
	void genLengths();
	void changeState(int newState);
	void reset();
	int getCurrent();
private:
	int currentState;
	 int numStates;
};

#endif /* states_h */
