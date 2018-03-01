#ifndef clock_h
#define clock_h

#include <chrono>
#include <thread>

class Clock {
    public:
    void start();
    int beat;
    int bpm = 120;
    Clock();
};

#endif
