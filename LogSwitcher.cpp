#include <iostream>
#include <cmath>

using namespace std;

double get_double_from_user() {
	double d;
	cin >> d;
	return d;
}

int main()
{
    double num = get_double_from_user();
	cout << log(num) / log(2);
}