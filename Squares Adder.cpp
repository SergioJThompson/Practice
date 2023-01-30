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
	int nums = get_int_from_user();
	int sum = 0;
	for (int i = 0; i < nums; i++)
		sum += pow(get_int_from_user(), 2);
	cout << sum;
}