#ifndef timing_h
#define timing_h

#include "ofMain.h"
#include "random.h"
#include <vector>
#include <numeric>

class Timing {
private:
    int frameRate;
    std::vector<float> timeSequence;
    int timeSequenceIndex;
    float accumulatedTimes;
    bool trigger;
public:
    int frameToMs(int frame);
    int frameToS(int frame);
    int MsToFrame(int ms);
    void addToSequence(float f);
    float getSequence(int i);
    void playSequence();
    void resetSequence();
    bool getTrigger();
    void displayData();
    int getNow();
    Timing();
};


#endif
