#ifndef timing_h
#define timing_h

#include "ofMain.h"
#include "random.h"
#include <vector>

// This class handles various timing considerations, such as keeping track of and manipulating the time in seconds since program was launched, allowing for time-based functionality
// within the program

class Timing {
private:
    int frameRate;
    int bpm;
    float elapsedTime;
    Random rand[32];
public:
    Timing();
    void update();
    float getElapsedTime();
    void generateRandom();
    void displayData();
};


#endif
