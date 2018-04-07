#include "states.h"

States::States() {
    currentState = 0;
}

void States::changeState() {
    ++currentState;
}

int States::getCurrent() {
    return currentState;
}
