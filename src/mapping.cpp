#include "mapping.h"

Map::Map() {
    
}

void Map::fill(float input) {
    while (values.size() < maxValues) {
        values.push_back(input);
    }
}

float Map::scale(float input, float mult, float offset, bool absolute) {
    if (absolute != true) {
        return (input * mult) + offset;
    } else {
        return (abs(input) * mult) + offset;
    }
}

void Map::empty() {
    if (values.size() != 0) values.clear();
}

void Map::print() {
    for (int i = 0; i < values.size(); ++i) {
        std::cout << values[i] << '\n';
    }
}

float Map::getIndex(int index) {
    return values[index];
}

