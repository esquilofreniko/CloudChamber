#ifndef timing_h
#define timing_h

#include "ofMain.h"
#include "mapping.h"
#include "clifford.h"
#include <vector>
#include <iostream>

// This class handles various timing considerations, such as keeping track of and manipulating the time in seconds since program was launched, allowing for time-based functionality
// within the program

class Timing {
private:
    Clifford clifford;
    Map map;
    int frameRate;
    std::vector<int> frameList;
    int frameListSize;
    int lowerFrame;
    int upperFrame;
    float elapsedTime;
    int displayColour;
    int displayX;
    int displayY;
public:
    Timing();
    int getListIndex(int i);
    void fillFrameList();
    int getFrame();
    void displayData();
};

#endif
