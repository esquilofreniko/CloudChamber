#include "movingAverage.h"

// work in progress

MovingAverage::MovingAverage() {
    
}

void MovingAverage::accum(float input) {
    values.push_back(input);
}

float MovingAverage::avg() {
    float sum = 0;
    if (values.size() > sampleSize) {
        for (int x = values.size() - sampleSize; x < values.size(); ++x) {
            sum += values[x];
        }
        return (sum / sampleSize);
    }

}
