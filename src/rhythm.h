#ifndef rhythm_h
#define rhythm_h

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>

class Rhythm {
private:
    int bpm;
    std::vector<int> rhythms;
public:
    Rhythm();
    void sleepFor(int time);
    void pattern();
};

#endif
