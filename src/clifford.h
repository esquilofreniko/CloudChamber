#ifndef clifford_h
#define clifford_h

#include <vector>
#include <cmath>

class Clifford {
    public:
    void init(float _a, float _b, float _c, float _d);
    void iterate();
    const int maxLength = 256;
    std::vector <float> x;
    std::vector <float> y;
    int count;
    float a;
    float b;
    float c;
    float d;
    Clifford();
};

#endif
