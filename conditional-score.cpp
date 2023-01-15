#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    cin >> x;
    cin >> y;
    if (x == y)
        cout << (x + y) * 2;
    else
        cout << x + y;
}
