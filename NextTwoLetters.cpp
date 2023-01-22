#include <iostream>
using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

char get_next_letter(char letter, int interval) {
	char next = letter + interval;
	if (next > 'z')
		next -= 26;
	return next;
}

int main()
{
    char c = get_char_from_user();
	cout << get_next_letter(c, 1) << get_next_letter(c, 2);
}