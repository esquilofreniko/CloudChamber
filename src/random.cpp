#include "random.h"

Random::Random() {
    distLower = 0.0;
    distUpper = 1.0;
}

float Random::gen() {
    std::random_device r;
    std::mt19937 mt(r());
    std::uniform_real_distribution<float> dist(distLower, distUpper);
    return dist(mt);
}
