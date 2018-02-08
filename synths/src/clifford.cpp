// Clifford attractor class

#include "clifford.h"

Clifford::Clifford() {
    
}

void Clifford::init(float _a, float _b, float _c, float _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

void Clifford::iterate() {
    if (count == 0) {
        x.push_back(sin(a) + (c * cos(a)));
        y.push_back(sin(b) + (d * cos(b)));
    } else {
        x.push_back(sin(a * y[count-1]) + (c * cos(a * x[count-1])));
        y.push_back(sin(b * x[count-1]) + (d * cos(b * y[count-1])));
    }
    ++count;
    if (count > maxLength) {
        count = 0;
    }
}
