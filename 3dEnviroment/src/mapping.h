#ifndef mapping_h
#define mapping_h

float scale(float input, float mult, float offset) {
    return abs(input * mult) + offset;
}

#endif
