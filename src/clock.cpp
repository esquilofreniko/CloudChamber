#include "clock.h"

Clock::Clock() {
    
}

void Clock::start() {
    while (true) {
        beat += 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
