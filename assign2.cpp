/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>


std::string longest_subs_without_repeating_chars(std::string s) {
    int longest_subs_start_idx = 0;
    int longest_subs_size = 1;
    for (int i = 0; i < s.size(); i++) {
        std::vector<char> used;
        used.push_back(s[i]);
        for (int j = i+1; j < s.size(); j++) {
            if (std::find(used.begin(), used.end(), s[j]) != used.end()) {
                if (j-i > longest_subs_size) {
                    longest_subs_start_idx = i;
                    longest_subs_size = j-i;
                }
                break;
            } else {
                used.push_back(s[j]);
            }
        }
    }
    return s.substr(longest_subs_start_idx, longest_subs_size);
}

int main() {
    std::cout << longest_subs_without_repeating_chars("abcabcbb");
    std::cout << longest_subs_without_repeating_chars("bbbbbb");
}
