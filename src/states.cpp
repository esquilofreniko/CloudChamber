#include "states.h"

States::States() {
    currentState = 0;
    numStates = 8;
}

void States::changeState() {
    ++currentState;
}

int States::getCurrent() {
    return currentState;
}
