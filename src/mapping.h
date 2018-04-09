#ifndef mapping_h
#define mapping_h

#include <algorithm>

// Some small functions for scaling and converting raw values

struct Map {
    double clip(double input, double min, double max) {
        return std::max(min, std::min(input, max));
    }
    double scale(double input, double inMin, double inMax, double outMin, double outMax) {
        return clip(((((outMax - outMin) * (input - inMin)) / inMax - inMin) + outMin), outMin, outMax);
    }
};

#endif
