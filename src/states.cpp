#include "states.h"

States::States() {
    currentState = 2;
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
