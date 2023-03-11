#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string filename = "rolling-stone-besteveralbums.csv";
    ifstream infile(filename);

    if (!infile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Skip first line
    string line;
    getline(infile, line);

    // Read and store all lines in a struct
    vector<string> lines;
    while (getline(infile, line)) {
        lines.push_back(line);
    }

    // Output the first three lines
    for (int i = 0; i < 3; i++) {
        cout << lines[i] << endl;
    }

    // Output the last three lines
    int num_lines = lines.size();
    for (int i = num_lines - 3; i < num_lines; i++) {
        cout << lines[i] << endl;
    }

    // Close the file
    infile.close();

    return 0;
}
