#include "states.h"

States::States() {
    currentState = 1;
    divisionSize = 24;
}

int States::getCurrent() {
    return currentState;
}

int States::getDivisions() {
    return divisionSize;
}
