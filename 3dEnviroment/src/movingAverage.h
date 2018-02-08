#ifndef movingAverage_h
#define movingAverage_h

#include "ofMain.h"
#include <vector>

class MovingAverage {
    public:
    std::vector<float> values;
    bool active;
    const int maxLength = 1000;
    void update(float input);
    MovingAverage();
};

#endif
