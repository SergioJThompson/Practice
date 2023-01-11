/**
* @brief Assignment 1
* @name Sergio Thompson
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

tuple <double, double> get_point_from_user() {
    double x;
    double y;
    cin >> x;
    cin >> y;
    return make_tuple(x, y);
}

vector<tuple<double, double>> get_points_from_user()
{
    vector<tuple<double, double>> points;
    for (int i = 0; i < 3; i++) {
        cout << "Enter x y for point " << i + 1 << ": ";
        points.push_back(get_point_from_user());
    }
    return points;
}

double calc_distance(tuple <double, double> point1, tuple <double, double> point2)
{
    double x1 = get<0>(point1);
    double y1 = get<1>(point1);
    double x2 = get<0>(point2);
    double y2 = get<1>(point2);
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

vector<double> calc_distances(vector<tuple<double, double>> points) {
    vector<double> distances;
    distances.push_back(calc_distance(points[0], points[1]));
    distances.push_back(calc_distance(points[0], points[2]));
    distances.push_back(calc_distance(points[1], points[2]));
    return distances;
}

double calc_semi_peri(double a, double b, double c) {
    return (a + b + c) / 2;
}

double calc_area(vector<double> distances) {
    double a = distances[0];
    double b = distances[1];
    double c = distances[2];
    double s = calc_semi_peri(a, b, c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void print_area(double area) {
    cout << "The area of the triangle is " << area << "\n";
}

int main()
{
    vector<tuple<double, double>> points = get_points_from_user();
    vector<double> distances = calc_distances(points);
    double area = calc_area(distances);
    print_area(area);
}
