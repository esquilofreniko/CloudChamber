#include "movingAverage.h"

// work in progress

MovingAverage::MovingAverage() {
    
}

void MovingAverage::update(float input) {
    while(active && values.size() < maxLength) {
        values.push_back(input);
    }
}
