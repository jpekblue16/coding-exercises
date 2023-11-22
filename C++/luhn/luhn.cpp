#include "luhn.h"

namespace luhn {

    bool valid(std::string number) {
                
        int total = 0;
        int index = 0; // number could contain non-digit characters and spaces, need to only count digits
        
        // loop from back of number, add each to the sum
        // every 2nd number, double and subtract 9 if needed
        // if sum is a factor of 10, number is valid
        // if any non-digit is found, number is invalid
        for (std::string::reverse_iterator it = number.rbegin(); it != number.rend(); ++it) {
            if (*it == ' ') {
                continue;
            }
            if (!isdigit(*it)) return false;

            int digit = *it - '0';
            if (index % 2 == 1) {
                digit = 2*digit;
                if (digit > 9) {
                    digit -= 9;
                }
                
            }
            std::cout << "; digit: " << digit << '\n';
            total += digit;
            index++;
            
        }

        // return false if no number found
        return total % 10 == 0 && index > 1;
    }

}  // namespace luhn