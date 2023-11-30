#include "matching_brackets.h"

#include <iostream>

namespace matching_brackets {

// returns true if the close char matches the open char eg '(' and ')' or '[' and ']'
bool isPair(char open,char close) {
    switch(close) {
        case ')':
            return open == '(';
        case ']':
            return open == '[';
        case '}':
            return open == '{';
    }

    return false;
}

bool check(std::string test) {

    // use a vector to track current open scope
    // if open character is found, add to scope
    // if close character is found that matches currently open scope, remove open character
    // if non matching close character is found, terminate with false
    // if entire string is parsed, scope will be empty if all open characters are paired
    std::vector<char> scope{};

    for (auto i = test.begin(); i != test.end(); ++i) {

        std::cout << "current char is " << *i << "\n";
        std::cout << "current scope is " << std::string(scope.begin(),scope.end()) << "\n";
        
        switch(*i) {
            case '(':
            case '[':
            case '{':
                scope.push_back(*i);
                break;
            case ')':
            case ']':
            case '}':
                if (scope.size() != 0 && isPair(scope.back(),*i)) {
                    scope.pop_back();
                } else {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return scope.size() == 0;
    
}

}  // namespace matching_brackets