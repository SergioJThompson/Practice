/**
* @brief Assignment 3
* @name Sergio Thompson
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

double get_double_from_user(string msg) {
    cout << msg;
    int d;
    cin >> d;
    return d;
}

double to_radians(double degrees) {
    return degrees * PI / 180;
}

double to_degrees(double radians) {
    return radians * 180 / PI;
}

bool is_obtuse_or_right(double angle_in_radians) {
    return angle_in_radians >= PI / 2;
}

bool roughly_equal(double x, double y) {
    return abs(x - y) < 0.0001;
}

int count_solutions(double a, double b, double A) {
    if (is_obtuse_or_right(A))
        return a < b || roughly_equal(a, b) ? 0 : 1;
    else {
        if (a < b) {
            double h = b * sin(A);
            if (a < h)
                return 0;
            else
                return roughly_equal(a, h) ? 1 : 2;
        }
        else return 1;
    }
}

double find_sinB(double a, double b, double A) {
    return b * sin(A) / a;
}

double find_B(double a, double b, double A) {
    return asin(find_sinB(a, b, A));
}

double find_C(double A, double B) {
    return PI - A - B;
}

double find_B2(double B) {
    return PI - B;
}

double find_C2 (double A, double B2) {
    return PI - A - B2;
}

void print_angles(double B, double C) {
    cout << "Angle B = " << to_degrees(B) << "\n";
    cout << "Angle C = " << to_degrees(C) << "\n";
}

int main() {
    double a = to_radians(get_double_from_user("Enter a: "));
    double b = to_radians(get_double_from_user("Enter b: "));
    double A = to_radians(get_double_from_user("Enter A: "));

    int solutions_count = count_solutions(a, b, A);

    if (solutions_count == 0)
        cout << "\nNo solution\n";
    else {
        double B = find_B(a, b, A);
        double C = find_C(A, B);
        cout << "\n";
        print_angles(B, C);
        if (solutions_count == 2) {
            double B2 = find_B2(B);
            double C2 = find_C2(A, B2);
            cout << "OR\n";
            print_angles(B2, C2);
        }
    }

}
