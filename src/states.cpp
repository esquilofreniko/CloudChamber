#include "states.h"

States::States() {
    currentState = 10;
    numStates = 12;
}

void States::changeState(int newState) {
	currentState = newState;
}

int States::getCurrent() {
    return currentState;
}
