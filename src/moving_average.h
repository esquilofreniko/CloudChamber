#ifndef movingAverage_h
#define movingAverage_h

#include <vector>

class MovingAverage {
private:
    std::vector<float> values;
    bool active;
    float sum;
    int sampleSize;
    const int maxLength = 1000;
public:
    void accum(float input);
    float getAverage();
    MovingAverage();
};

#endif
