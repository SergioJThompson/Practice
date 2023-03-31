/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string s;
    getline(std::cin, s);

    std::string no_vowels;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            no_vowels += s[i];
        }
    }

    std::cout << no_vowels;
}
