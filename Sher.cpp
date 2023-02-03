#include <iostream>
#include <string>
using namespace std;

//Turn off loops - you should not need them!
#define for     "OhNoYouDont"
#define while   "GetThatOutOfMyKitchen"


//Do not modify anything on or above the line below this
//YOUR_CODE_BELOW

int main()
{
    string s;
	cin >> s;
	int length = s.length();
	if (length <= 4)
		cout << s;
	else
		cout << s.at(0) << s.at(1) << s.at(length - 2) << s.at(length - 1); 
}