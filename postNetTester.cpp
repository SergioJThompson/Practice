/**
* @brief Assignment 7
* @name Sergio Thompson
*/

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Tell clang analyzer to ignore doctest.h
#ifndef __clang_analyzer__
#include "doctest.h"
#endif

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include "postNetFunctions.h"

TEST_CASE("splitByComma: basic case") {
    std::string line = "Rochester,NY,14614";
    std::string* parts = splitByComma(line);
    CHECK(parts[0] == "Rochester");
    CHECK(parts[1] == "NY");
    CHECK(parts[2] == "14614");
    delete[] parts;
}

TEST_CASE("splitByComma: hyphenated zip") {
    std::string line = "Birmingham,AL,35285-2949";
    std::string* parts = splitByComma(line);
    CHECK(parts[0] == "Birmingham");
    CHECK(parts[1] == "AL");
    CHECK(parts[2] == "35285-2949");
    delete[] parts;
}

TEST_CASE("splitByComma: space") {
    std::string line = "Apache Junction,AZ,85219";
    std::string* parts = splitByComma(line);
    CHECK(parts[0] == "Apache Junction");
    CHECK(parts[1] == "AZ");
    CHECK(parts[2] == "85219");
    delete[] parts;
}

TEST_CASE("charToBits: basic case") {
    char c = '3';
    CHECK(charToBits(c) == "00110");
}

TEST_CASE("charToBits: not a digit") {
    char c = '-';
    CHECK(charToBits(c) == "");
}

TEST_CASE("zipToBits: basic case") {
    std::string zip = "12345";
    std::string bits = zipToBits(zip);
    CHECK(bits == "10001100101001100100101010010101");
}

TEST_CASE("zipToBits: hyphenated zip") {
    std::string zip = "23456-7890";
    std::string bits = zipToBits(zip);
    CHECK(bits == "1001010011001001010100110010001100101010011000011001");
}

TEST_CASE("zipSum: basic case") {
    std::string zip = "12345";
    int sum = zipSum(zip);
    CHECK(sum == 15);
}

TEST_CASE("zipSum: hyphenated zip") {
    std::string zip = "23456-7890";
    int sum = zipSum(zip);
    CHECK(sum == 44);
}

TEST_CASE("checksum: basic case") {
    std::string zip = "12345";
    std::string myChecksum = checksum(zip);
    CHECK(myChecksum == "01010");
}

TEST_CASE("checksum: hyphenated zip") {
    std::string zip = "23456-7890";
    std::string myChecksum = checksum(zip);
    CHECK(myChecksum == "01100");
}

TEST_CASE("checksum: lowest zip") {
    std::string zip = "00501";
    std::string myChecksum = checksum(zip);
    CHECK(myChecksum == "01001");
}

TEST_CASE("getPostNETOutput: basic case") {
    std::string line = "New York,NY,56458";
    std::string output = getPostNETOutput(line);
    CHECK(output == "New York, NY 56458\n10101001100010010101010010001011\n");
}

TEST_CASE("getPostNETOutput: hyphenated zip") {
    std::string line = "Oklahoma City,OK,73124-2412";
    std::string output = getPostNETOutput(line);
    CHECK(output == "Oklahoma City, OK 73124-2412\n1100010011000011001010100100101010010001100101010011\n");
}

