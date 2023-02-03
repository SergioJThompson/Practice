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
	int middle = s.length() / 2;
	cout << s.at(0) << s.at(middle) << s.at(s.length()-1);
}