#ifndef counter_h
#define counter_h

#include <iostream>

class Counter {
private:
    int x;
    int cycles;
    int max;
public:
    void step();
    void setMax(int _max);
    void reset();
    void print();
    int getX();
    Counter();
};

#endif
