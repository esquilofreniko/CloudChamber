// Clifford attractor class

#include "clifford.h"

Clifford::Clifford() {
    
}

void Clifford::init(float initA, float initB, float initC, float initD) {
    x = y = 1;
    a = initA;
    b = initB;
    c = initC;
    d = initD;
}

void Clifford::iterate() {
    x = sin(a * y) + (c * cos(a * x));
    y = sin(b * x) + (d * cos(b * y));
}
