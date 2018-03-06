#include "moving_average.h"

MovingAverage::MovingAverage() {
    sampleSize = 20;
}

void MovingAverage::accum(float input) {
    values.push_back(input);
}

float MovingAverage::getAverage() {
    if (values.size() > sampleSize) {
        for (int x = values.size() - sampleSize; x < values.size(); ++x) {
            sum += values[x];
        }
        return (sum / sampleSize);
    }
}
