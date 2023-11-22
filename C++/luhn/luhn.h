#if !defined(LUHN_H)
#define LUHN_H

#include <string>
#include <iostream>

namespace luhn {
bool valid(std::string number);
}  // namespace luhn

#endif // LUHN_H