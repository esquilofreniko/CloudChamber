#include "states.h"

States::States() {
    currentState = 0;
    numStates = 8;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}
