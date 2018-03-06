#ifndef random_h
#define random_h

#include <random>

class Random {
    private:
    float distLower;
    float distUpper;
    public:
    float gen();
    Random();
};

#endif
