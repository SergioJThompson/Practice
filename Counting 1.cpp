#include <iostream>
using namespace std;

int get_int_from_user() {
	int n;
	cin >> n;
	return n;
}

int main()
{
    int max = get_int_from_user();
	int i = 1;
	while (i <= max) {
		cout << i;
		i++;
	}
}