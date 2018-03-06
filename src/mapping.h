#ifndef mapping_h
#define mapping_h

#include <vector>
#include <iostream>
#include <cmath>

class Map {
private:
    std::vector <float> values;
    int maxValues = 12;
public:
    void fill(float input);
    void empty();
    void print();
    float getIndex(int index);
    float scale(float input, float mult, float offset, bool abs);
    Map();
};

#endif
