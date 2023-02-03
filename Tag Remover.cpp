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
    string beforeTag;
	getline(cin, beforeTag, '[');
	
	string tag;
	getline(cin, tag, ']');
	
	string inTag;
	getline(cin, inTag, '[');
	
	cout << tag << ':' << inTag;
}