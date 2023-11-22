#include "sieve.h"

namespace sieve {

std::vector<int> primes(int limit) {

    //create vector with last index being limit, all values as true (unmarked)
    std::vector<bool> all(limit+1,true);

    std::vector<int> result{};

    //loop over initial vector and find first true value >= 2
    for (int x = 2; x <= limit; ++x) {
        std::cout << x << "\n"; 
        
        //if unmarked value is found, add it to result and mark all multiples; otherwise continue
        if (all[x]) {
            result.push_back(x);
            if (x*x <= limit) {
                for (int i = x*x; i <= limit; i+= x) {
                    std::cout << "marking " << i << "\n";
                    all[i] = false;
                }
            }
        }
    }

    return result;
}

}  // namespace sieve