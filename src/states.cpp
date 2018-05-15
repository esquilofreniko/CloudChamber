#include "states.h"

States::States() {
    currentState = 1;
    numStates = 8;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}
