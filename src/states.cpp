#include "states.h"

States::States() {
    currentState = 9; // the first state should be 9
    numStates = 11;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}
