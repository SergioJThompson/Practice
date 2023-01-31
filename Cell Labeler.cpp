#include <iostream>
using namespace std;

int main()
{
    int cols, rows;
    cin >> cols >> rows;

    for (int row = 1; row <= rows; row++) {
		for (char col = 0; col < cols; col++) {
			cout << char('A' + col) << row << " ";
		}
		cout << "\n";
	}
}