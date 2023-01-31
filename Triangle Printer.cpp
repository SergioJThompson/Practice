#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    for (int row = 1; row <= size; row++) {
		cout << "*";
        for (int stars = 1; stars < row; stars++)
			cout << "**";
        cout << endl;
    }
}