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
    double opp = get_double_from_user();
	double adj = get_double_from_user();
	cout << atan(opp/adj);
}