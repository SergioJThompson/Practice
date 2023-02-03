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
	int i = s.find("cat");
	if (i == 0 || i == 1)
		cout << "true";
	else
		cout << "false";
}