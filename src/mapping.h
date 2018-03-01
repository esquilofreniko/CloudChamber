#ifndef mapping_h
#define mapping_h

float scale(float input, float inputLow, float inputHigh, float outputLow, float outputHigh) {
    float output = ((input - inputLow) / (inputHigh - inputLow) * (outputHigh - outputLow) + outputLow);
    return output;
}

#endif
