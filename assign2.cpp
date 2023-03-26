/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>

int print_fib(int prev_fib_num, int current_fib_num, int nums_remaining) {
    if (nums_remaining <= 0)
        return 0;

    std::cout << current_fib_num << " ";
    nums_remaining--;

    if (current_fib_num == 0)
        return print_fib(0, 1, nums_remaining);
    return print_fib(current_fib_num, prev_fib_num + current_fib_num, nums_remaining);
}

int main() {
    int num_of_nums;
    std::cin >> num_of_nums;
    print_fib(0, 0, num_of_nums);
}
