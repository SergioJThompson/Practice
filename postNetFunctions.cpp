/**
* @brief Assignment 7
* @name Sergio Thompson
*/

#include "postNetFunctions.h"
#include <iostream>
#include <sstream>

std::string* splitByComma(std::string& s) {
    std::string* parts = new std::string[3];
    std::string part;
    std::stringstream ss(s);

    int i = 0;
    while (std::getline(ss, part, ','))
        parts[i++] = part;

    return parts;
}

std::string charToBits(char c) {
    switch (c) {
        case '1':
            return "00011";
        case '2':
            return "00101";
        case '3':
            return "00110";
        case '4':
            return "01001";
        case '5':
            return "01010";
        case '6':
            return "01100";
        case '7':
            return "10001";
        case '8':
            return "10010";
        case '9':
            return "10100";
        case '0':
            return "11000";
        default:
            return "";
    }
}

int zipSum(std::string zip) {
    int zipSum = 0;
    for (int i = 0; i < zip.length(); i++) {
        std::string s(1, zip[i]);
        if (s == "-")
            continue;
        zipSum += std::stoi(s);
    }
    return zipSum;
}

std::string checksum(std::string zip) {
    int checksumInt = 10 - (zipSum(zip) % 10);
    char checksumChar = '0' + checksumInt;
    return charToBits(checksumChar);
}

std::string zipToBits(std::string zip) {
    std::string bits = "1";

    for (int i = 0; i < zip.length(); i++)
        bits.append(charToBits(zip[i]));

    bits.append(checksum(zip));

    return bits.append("1");
}

std::string getPostNETOutput(std::string line) {
    std::string* parts = splitByComma(line);
    std::string formatted;
    formatted.append(parts[0] + ", " + parts[1] + " " + parts[2] + "\n");
    return formatted.append(zipToBits(parts[2]) + "\n");
}
