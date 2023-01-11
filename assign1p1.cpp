/**
* @brief Assignment 1
* @name Sergio Thompson
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << n % 10          << " one(s)\n";
    cout << n / 10 % 10     << " ten(s)\n";
    cout << n / 100 % 10    << " hundred(s)\n";
    cout << n / 1000        << " thousand(s)\n";
}
