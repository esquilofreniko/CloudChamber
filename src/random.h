#ifndef random_h
#define random_h

#include <random>

// A simple random number generator class using uniform distribution

class Random {
private:
    float value;
public:
    void gen(float distLower, float distUpper);
    float output();
};

#endif
