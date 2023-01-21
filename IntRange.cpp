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
    double val = get_double_from_user();
	cout << floor(val) << " " << ceil(val);
}