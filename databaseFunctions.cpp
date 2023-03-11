#include "databaseFunctions.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> get_file_contents_as_strings(std::string filename) {
    std::ifstream infile(filename);

    if (!infile.is_open())
        std::cout << "Error opening file" << std::endl;

    std::string line;
    getline(infile, line);  // Skip first line

    std::vector<std::string> lines;
    while (getline(infile, line))
        lines.push_back(line);
    return lines;
}

void print_first_three_last_three(std::vector<std::string> lines) {
    for (int i = 0; i < 3; i++)
        std::cout << lines[i] << std::endl;
    int num_lines = lines.size();
    for (int i = num_lines - 3; i < num_lines; i++)
        std::cout << lines[i] << std::endl;
}
