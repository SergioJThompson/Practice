/**
* @brief Assignment 4
* @name Sergio Thompson
*/

#include <iostream>
#include <cmath>

using namespace std;

int get_int_from_user(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
}

double get_double_from_user(const string& msg) {
    cout << msg;
    double d;
    cin >> d;
    return d;
}

string line(int year, int month, double balance) {
    return to_string(year) + " / " + to_string(month) + " / " + to_string(balance) + "\n";
}

string table(double monthly_inv, double monthly_multiplier, int years) {
    string table;
    double balance = monthly_inv;
    for (int year = 1; year <= years; year++) {
        for (int month = 1; month <= 12; month++) {
            table += line(year, month, balance);
            balance = balance * monthly_multiplier + monthly_inv;
        }
    }
    return table;
}

int main() {
    double monthly_inv = get_double_from_user("Enter monthly investment: ");
    double apr = get_double_from_user("Enter APR: ");
    int years = get_int_from_user("Enter number of years: ");

    double monthly_multiplier = pow(apr*0.01+1, 1/12.0);

    cout << "\n\n";
    cout << "Year# / Month# / Balance\n";
    cout << table(monthly_inv, monthly_multiplier, years);

}