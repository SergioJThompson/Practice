#include <iostream>
using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

int main()
{
    char c = get_char_from_user();
	while (c != '.') {
		if (c != ' ')
			cout << c;
		c = get_char_from_user();
	}
}