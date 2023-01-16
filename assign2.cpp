/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>

using namespace std;

double get_double_from_user(string msg) {
    cout << msg;
    double d;
    cin >> d;
    return d;
}


string decision(double gpa, double sat) {
    if (gpa >= 3.5) {
        if (sat >  1400) return "Admit";
        if (sat >= 1100) return "Waitlist";
    }

    if (gpa >= 3.0) {
        if (sat >  2000) return "Admit";
        if (sat >= 1500) return "Waitlist";
    }

    if (sat >= 2200) return "Admit";

    return "Deny";
}

int main()
{
    double gpa = get_double_from_user("Enter GPA: ");
    if (gpa >= 4.0)
        cout << "\nAdmit\n";
    else {
        double sat = get_double_from_user("Enter SAT: ");
        cout << "\n" + decision(gpa, sat) + "\n";
    }
}
