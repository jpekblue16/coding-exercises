#include "hamming.h"

namespace hamming {

    int compute(const std::string& a, const std::string& b) {
        if (a.length() != b.length()) throw std::domain_error("strings must be equal length");

        if ((a != "" ) != ( b != "")) throw std::domain_error("neither string can be empty");

        int count = 0;
        for (std::string::size_type i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) count++;
        }
        return count;
    }

}  // namespace hamming
