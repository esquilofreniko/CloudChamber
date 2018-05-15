#include "states.h"

States::States() {
    currentState = 10; // the first state should be 10
    numStates = 12;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}
