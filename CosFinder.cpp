#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

double get_double_from_user() {
	double d;
	cin >> d;
	return d;
}

double to_radians(double degrees) {
	return degrees * PI / 180;
}

int main()
{
    double degrees = get_double_from_user();
	double adj = get_double_from_user();
	cout << adj / cos(to_radians(degrees));
}