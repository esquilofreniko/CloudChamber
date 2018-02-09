#ifndef clock_h
#define clock_h

#include <chrono>
#include <thread>

class Clock {
    public:
    void update();
    int tick;
    int bpm = 120;
    Clock();
};

#endif
