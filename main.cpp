#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

double get_double_from_user(string msg) {
    cout << msg;
    int i;
    cin >> i;
    return i;
}

double to_degrees(double radians) {
    return radians * (180/PI);
}

double find_sinB(double a, double b, double A) {
    return (b * sin(A)) / a;
}

int main() {
    double a = get_double_from_user("Enter a: ");
    double b = get_double_from_user("Enter b: ");
    double A = get_double_from_user("Enter A: ");
    double B = to_degrees(asin(find_sinB(a, b, A)));

    double sinA = sin(A);
    double sinADegrees = to_degrees(sin(A));
    cout << "Sin A radians: " << sinA;
    cout << "Sin A degrees: " << sinADegrees;

    cout << "Angle B = " << B << " degrees";
}
