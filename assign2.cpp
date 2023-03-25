/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>


int main()
{
    int a;
    int b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    std::cout << "Pointer A: " << ptrA;
    std::cout << "Pointer B: " << ptrB;
}
