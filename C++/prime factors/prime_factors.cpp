#include "prime_factors.h"

namespace prime_factors {

int findFirstFactor(int target, int start) {
    // find the first factor of the given number
    // if result is == target, target is prime

    int factorLimit = static_cast<int>(std::sqrt(target)); // only need to check for factors up to sqrt(target), since lowest factor is found first

    for (int x = start; x<= factorLimit; ++x) {
        if (target % x == 0) {
            // x is a factor of target
            return x;
        }
    }

    return target;
}

std::vector<int> of(int target) {

    std::vector<int> factors{};

    int lastFoundFactor = 2; // start finding factors from the previous found factor, smallest prime factor is 2

    // loop until last factor found
    while (target > 1) {
        // find the first prime factor of the current target and add to vector
        // start at the previously found factor, find as many of the smallest factor as possible before continuing
        int primeFactor = findFirstFactor(target,lastFoundFactor);
        lastFoundFactor = primeFactor;

        // add found factor to vector
        factors.push_back(primeFactor);

        // divide target by found factor and continue
        target /= primeFactor;
    }

    return factors;
}

}  // namespace prime_factors