/**
* @brief Assignment 7
* @name Sergio Thompson
*/

#include <iostream>
#include <fstream>
#include "postNetFunctions.h"

int main()
{
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");
    std::string line;

    while (std::getline(infile, line)) {
        std::string output = getPostNETOutput(line);
        outfile << output;
        outfile.flush();
    }

    outfile.close();
    return 0;
}
