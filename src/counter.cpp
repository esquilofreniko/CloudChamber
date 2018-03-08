#include "counter.h"

Counter::Counter() {
    max = 2048;
}

void Counter::step() {
    x = (x + 1) % max;
    if (x == 0) cycles += 1;
}

int Counter::getX() {
    return x;
}

void Counter::setMax(int _max) {
    max = _max;
}

void Counter::reset() {
    if (x != 0) x = 0;
}

void Counter::print () {
    std::cout << x << '\n';
}
