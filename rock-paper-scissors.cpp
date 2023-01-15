#define GET_VARIABLE_NAME(Variable) (#Variable)
#include <iostream>

using namespace std;

enum hands { rock = 1, paper = 3 };

string winning_letter(int a, int b) {
    if (a == rock && b == paper)
        return "B";
    if (a == paper && b == rock)
        return "A";
    if (a < b)
        return "A";
    return "B";
}

int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    if (a == b)
        cout << "tie";
    else
        cout << winning_letter(a, b);
}
