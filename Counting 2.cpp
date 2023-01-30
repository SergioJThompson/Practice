#include <iostream>
using namespace std;

int get_int_from_user() {
	int x;
	cin >> x;
	return x;
}

int main()
{
    int sum = get_int_from_user();
	int inc = get_int_from_user();
    int end = get_int_from_user();
    while (sum <= end) {
		cout << sum;
		sum = sum + inc;
	}
	if (sum - inc < end)
		cout << sum;
}