#include "random.h"

void Random::gen(float distLower, float distUpper) {
    std::random_device r;
    std::mt19937 mt(r());
    std::uniform_real_distribution<float> dist(distLower, distUpper);
    value = dist(mt);
}

float Random::output() {
    return value;
}
