/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <cmath>

int calc_gcd(int m, int n) {
    int lowest = std::min(m, n);
    int gcd = 1;
    for (int div = lowest; div >= 2; div--) {
        if (m % div == 0 && n % div == 0) {
            gcd = div;
            break;
        }
    }
    return gcd;
}

int main() {
    int m;
    int n;
    int gcd;

    std::cin >> m;
    std::cin >> n;

    gcd = calc_gcd(m, n);
    std::cout << gcd;
}
