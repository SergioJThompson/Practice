#include <iostream>
#include <cmath>
using namespace std;

int get_int_from_user() {
	int x;
	cin >> x;
	return x;
}

int main()
{
    int base = get_int_from_user();
	int exponent = 0;
	int product = pow(base, exponent);
	while (product <= 1000) {
		cout << product << " ";
		exponent++;
		product = pow(base, exponent);
	}
}