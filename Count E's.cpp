#include <iostream>
using namespace std;

int main()
{
    string s;
	getline(cin, s);
	
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s.at(i) == 'e')
			count++;
	cout << count;
}