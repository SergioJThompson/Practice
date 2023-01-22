#include <iostream>
#include <cctype>

using namespace std;

char get_char_from_user() {
	char c;
	cin >> c;
	return c;
}

string get_evaluation(char a, char b, char c) {
	if (!isdigit(a) && !isdigit(b) && !isdigit(c))
		return "NO";
	if (!ispunct(a) && !ispunct(b) && !ispunct(c))
		return "NO";
	return "YES";
}

int main()
{
    char a = get_char_from_user();
	char b = get_char_from_user();
    char c = get_char_from_user();
	cout << get_evaluation(a, b, c);
}