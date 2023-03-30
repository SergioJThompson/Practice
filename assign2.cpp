/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <string>
#include <cmath>

bool is_perfect_square(int x) {
    double square = sqrt(x);
    return (floor(square) == ceil(square));
}

int main() {
    int x;
    int y;

    std::cin >> x;
    std::cin >> y;

    for (int i = x; i <= y; i++) {
        if (is_perfect_square(i)) {
            std::cout << i << " ";
        }
    }
}
