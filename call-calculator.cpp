#include <iostream>

using namespace std;

int main()
{
    int dur;
    cin >> dur;

    double cost;
    if (dur <= 10)
        cost = 5;
    else if (dur < 30)
        cost = dur * .5;
    else
        cost = 15 + (dur - 30) * .3;
    cout << cost;
}
