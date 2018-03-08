#ifndef clifford_h
#define clifford_h

#include <vector>
#include <cmath>
#include <iostream>

class Clifford {
    private:
    int maxLength;
    int count;
    float a;
    float b;
    float c;
    float d;
    std::vector<float> x;
    std::vector<float> y;
    public:
    void iterate();
    void modulate(float _a, float _b, float _c, float _d);
    float getX(int xIndex);
    float getY(int yIndex);
    int getSizeX();
    int getSizeY();
    Clifford();
    ~Clifford();
};

#endif
