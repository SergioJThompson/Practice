#include <iostream>
using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

int main()
{
    char a = get_char_from_user();
	char b = get_char_from_user();
	for (a; a < b; a++)
		cout << a << ",";
	cout << a;
}