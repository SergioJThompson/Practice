#include <iostream>
#include <cctype>
using namespace std;

int main()
{
     string word;

//Do not modify anything on or above the line below this
//YOUR_CODE_BELOW

	cin >> word;
	for (int i = 0; i < word.length(); i++)
		word[i] = toupper(word[i]);

//YOUR_CODE_ABOVE
//Do not modify anything on or below the line above this
    cout << word;
}