#include "states.h"

States::States() {
    currentState = 9; //First State Should be 9
    numStates = 11;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}

void States::reset() {
	currentState = 1;
}
