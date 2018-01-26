#ifndef clifford_h
#define clifford_h

#include "ofMain.h"

class Clifford {
    public:
    void init(float initA, float initB, float initC, float initD);
    void iterate();
    float x;
    float y;
    float a;
    float b;
    float c;
    float d;
    Clifford();
};

#endif
