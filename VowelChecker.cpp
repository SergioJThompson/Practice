#include <iostream>
#include <cctype>

using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

string classify(char c) {
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return "vowel";
	return "consonant";
}

int main()
{
    char c = get_char_from_user();
	cout << classify(c);
}