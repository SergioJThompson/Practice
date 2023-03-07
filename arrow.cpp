#include <iostream>
using namespace std;
#include <cstring>

int main() 
{
    std::string s;
    std::cin >> s;
    int length = s.length();
    
    for (int row = 0; row < s.length(); row++) {
    	for (int spaces = 0; spaces < (s.length() - row + 1) * 2; spaces++) {
    		std::cout << " ";
    	}
    	std::cout << s[row];
    	if (row > 0) {
    		for (int spaces = 0; spaces < 3 + (row - 1) * 4; spaces++) {
    			std::cout << " ";
    		}
    		std::cout << s[row];
    	}
    	std::cout << endl;
    }
}