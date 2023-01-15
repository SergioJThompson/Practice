#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;
    if (x >= 100.0)
        x = x * 0.9;
    cout << x;
}
