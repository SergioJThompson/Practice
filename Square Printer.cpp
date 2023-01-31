#include <iostream>
using namespace std;

int get_int_from_user() {
	int x;
	cin >> x;
	return x;
}

int main()
{
    int n = get_int_from_user();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << "*";
		cout << "\n";
	}
}