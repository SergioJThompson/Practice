#include <iostream>
#include <cmath>
using namespace std;

double solveQuadratic(double a, double b, double c, int multiplier) {
	return (-b + multiplier * sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
}

void solveQuadratic(double a, double b, double c, double& x1, double& x2) {
	x1 = solveQuadratic(a, b, c, 1);
	x2 = solveQuadratic(a, b, c, -1);
}

int main()
{
    double answer1 = 0, answer2 = 0;
    double in1, in2, in3;
    cin >> in1 >> in2 >>  in3;
    solveQuadratic(in1, in2, in3, answer1, answer2);

    cout << answer1<< ", " << answer2 << endl;
}