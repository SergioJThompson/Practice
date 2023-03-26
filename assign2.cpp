/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <cmath>

bool is_prime(int x) {
    for (int divisor = 2; divisor <= sqrt(x); divisor++) {
        if (x % divisor == 0)
            return false;
    }
    return true;
}

void print_primes(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i))
            sum += i;
    }
    std::cout << sum;
}

int main() {
    int n;
    std::cin >> n;
    print_primes(n);
}
