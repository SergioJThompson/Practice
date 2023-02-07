#include <iostream>
#include <fstream>

using namespace std;

int getIndexNthOccurrence(string s, int n, char c)
{
    int i = 0;
    int occur = 0;
    while (i < s.length()) {
        if (s[i] == c)
            occur++;
        if (occur == n)
            return i;
        i++;
    }
    return -1;
}


int main() {
    ifstream file("Images.txt");
    string line;
    int longestFileLength = 0;
    while (getline(file,line)) {
        unsigned first = 1 + getIndexNthOccurrence(line, 4, '/');
        unsigned last = line.find('?');
        string fileStr = line.substr(first, last - first);
        cout << fileStr << endl;
    }
    file.close();
    return 0;
}
