#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    for(int row = 1; row <= size; row++) {
		for(int spaces = size - row; spaces > 0; spaces--)
			cout << " ";
        for(int stars = row; stars > 0; stars--)
			cout << "*";
        cout << endl;
    }
}