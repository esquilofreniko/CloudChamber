#ifndef timing_h
#define timing_h

#include "ofMain.h"
#include "mapping.h"
#include <vector>
#include <iostream>

// Handling for various time related considerations for the program

class Timing {
private:
    int frameRate;
    int displayCol;
    int displayX;
    int displayY;
public:
    Timing();
    int getFrame();
    void displayData();
};

#endif
