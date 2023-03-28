/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <string>
#include <cmath>

bool is_palindrome(std::string s) {
    std::string lowered;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]))
            lowered += tolower(s[i]);
    }

    std::string lowered_reversed;
    for (int i = 0; i < lowered.size(); i++) {
        lowered_reversed = lowered[i] + lowered_reversed;
    }

    return (lowered == lowered_reversed);
}

int main() {
    std::string s;
    getline (std::cin, s);

    if (is_palindrome(s))
        std::cout << "It's a palindrome!";
    else
        std::cout << "Not a palindrome.";
}
