/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>


int main()
{
    int val = 5;
    std::cout << val;

    int* ptr = &val;
    *ptr += 5;
    std::cout << val;
}
