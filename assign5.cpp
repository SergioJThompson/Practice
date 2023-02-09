/**
* @brief Assignment 5
* @name Sergio Thompson
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int findNthOccurrence(string s, int n, char ch)
{
    int i = 0;
    int count = 0;
    while (i < s.length()) {
        if (s[i] == ch)
            count++;
        if (count == n)
            return i;
        i++;
    }
    return -1;
}

string getName(const string& line) {
    unsigned first = 1 + findNthOccurrence(line, 4, '/');
    unsigned last = line.find('?');
    return line.substr(first, last - first);
}

string getType(const string& line) {
    unsigned first = 1 + findNthOccurrence(line, 2, '.');
    unsigned last = line.find('?');
    return line.substr(first, last - first);
}

string getWidth(const string& line) {
    string sub = line.substr(1 + line.find('?'));
    unsigned last = sub.find('x');
    return sub.substr(0, last);
}

string getHeight(const string& line) {
    string sub = line.substr(1 + line.find('?'));
    unsigned first = 1 + sub.find('x');
    unsigned last = sub.find('\t');
    return sub.substr(first, last - first);
}

string get_spaces(int n) {
    string spaces;
    for (int i = 0; i < n; i++)
        spaces += " ";
    return spaces;
}

double getkB(const string& line) {
    string bytes = line.substr(1 + line.find_last_of('\t'));
    return stoi(bytes) / 1024.0;
}

string round(double d) {
    stringstream stream;
    stream << fixed << setprecision(1) << d;
    return stream.str();
}

int main() {
    ifstream file("Images.txt");
    string line;
    int longestNameLength = 0;

    while (getline(file,line)) {
        int nameLength = getName(line).length();
        if (nameLength > longestNameLength)
            longestNameLength = nameLength;
    }

    cout << "Name" << get_spaces(1 + longestNameLength);
    cout << "Type" << get_spaces(3);
    cout << "Width" << get_spaces(3);
    cout << "Height" << get_spaces(3);
    cout << "Size" << endl;

    file.clear();
    file.seekg(0, ios::beg);

    double kBSum = 0.0;

    while (getline(file,line)) {
        string name = getName(line);
        cout << name << get_spaces(longestNameLength + 5 - name.length());

        string type = getType(line);
        cout << type << get_spaces(7 - type.length());

        string width = getWidth(line);
        cout << width << get_spaces(8 - width.length());

        string height = getHeight(line);
        cout << height << get_spaces(9 - height.length());

        double kB = getkB(line);
        kBSum += kB;

        string size = round(kB);
        cout << size << endl;
    }

    file.close();

    cout << "Total Size:" << get_spaces(longestNameLength + 18) << round(kBSum);
}
