#include "rhythm.h"

Rhythm::Rhythm() {
    bpm = 120;
    rhythms = {1000, 2000, 3000, 4000};
}

void Rhythm::sleepFor(int time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Rhythm::pattern() {
    int i = 0;
    while (i < rhythms.size()) {
        std::cout << rhythms[i] << '\n';
        sleepFor(rhythms[i]);
        ++i;
    }
}
