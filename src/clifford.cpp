#include "clifford.h"

Clifford::Clifford() {
    maxLength = 256;
    a = -1.7;
    b = 1.3;
    c = -0.1;
    d = -1.2;
    std::cout << "Clifford attractor object instantiated." << '\n';
    std::cout << "A: " << a << " B: " << b << " C: " << c << " D: " << d << '\n';
}

Clifford::~Clifford() {
    std::cout << "Clifford attractor object deallocated." << '\n';
    
}

void Clifford::modulate(float _a, float _b, float _c, float _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    std::cout << "A: " << a << " B: " << b << " C: " << c << " D: " << d << '\n';
}

void Clifford::iterate() {
    if (count == 0) {
        x.push_back(sin(a) + (c * cos(a)));
        y.push_back(sin(b) + (d * cos(b)));
    } else {
        x.push_back(sin(a * y[count-1]) + (c * cos(a * x[count-1])));
        y.push_back(sin(b * x[count-1]) + (d * cos(b * y[count-1])));
    }
    count = (count + 1) % maxLength;
}

float Clifford::getX(int xIndex) {
    if (xIndex >= 0 && xIndex <= x.size()) {
        return x[xIndex];
    } else {
        return 0;
    }
}

float Clifford::getY(int yIndex) {
    if (yIndex >= 0 && yIndex <= y.size()) {
    return y[yIndex];
    } else {
        return 0;
    }
}

int Clifford::getSizeX() {
    return x.size();
}

int Clifford::getSizeY() {
    return y.size();
}
