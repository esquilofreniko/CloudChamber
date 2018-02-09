#include "clock.h"

Clock::Clock() {
    
}

void Clock::update() {
    ++tick;
    std::this_thread::sleep_for(std::chrono::milliseconds(60000 / bpm));
}
