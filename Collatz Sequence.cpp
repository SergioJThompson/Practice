#include <iostream>
using namespace std;

int get_int_from_user() {
	int x;
	cin >> x;
	return x;
}

int operate(int x) {
	if (x % 2 == 0)
		return x / 2;
	return x * 3 + 1;
}

int main()
{
    int n = get_int_from_user();
	while (n != 1) {
		cout << n << " ";
		n = operate(n);
	}
	cout << 1 << " ";
}