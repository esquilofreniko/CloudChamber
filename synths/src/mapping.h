#ifndef mapping_h
#define mapping_h

#include "ofMain.h"

float xScale(float input, float mult, float offset) {
    return abs(input * mult) + offset;
}

#endif
