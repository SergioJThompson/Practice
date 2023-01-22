#include <iostream>
using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

int group(char c) {
	if (c <= 'J') return 1;
	if (c <= 'P') return 2;
	return 3;
}

int main()
{
    char c = get_char_from_user();
	cout << group(c);
}