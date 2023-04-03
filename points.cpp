#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Point {
private:
	double x;
	double y;

public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(double startX, double startY) {
		x = startX;
		y = startY;
	}

	double getX() {
		return x;
	}
	
	double getY() {
		return y;
	}
	
	void translate(double deltaX, double deltaY) {
		x += deltaX;
		y += deltaY;
	}
};

int main()
{
	srand(static_cast<int>(time(0)));
	Point p1(rand() % 10, rand() % 10);
	Point p2(p1.getX(), p2.getY());
	p2.translate(4, -3);
	cout << p2.getX() - p1.getX() << endl;
	cout << p2.getY() - p1.getY() << endl;
}