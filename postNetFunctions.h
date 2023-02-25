/**
* @brief Assignment 7
* @name Sergio Thompson
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#endif // FUNCTIONS_H

/**
 * @brief Splits a line by comma and returns a string array. Assumes two commas.
 *
 * @param s The line to split.
 * @return std::string* Pointer to a string array of parts.
 */
std::string* splitByComma(std::string& s);

/**
 * @brief Calculates the sum of digits in a zip code. Ignores non-digit characters.
 *
 * @param zip The zip code.
 * @return int The sum of digits in the zip code.
 */
int zipSum(std::string zip);

/**
 * @brief Converts a digit character to a 5-bit binary string. Ignores non-digit characters.
 *
 * @param c The character to convert.
 * @return std::string A binary string representing the character.
 */
std::string charToBits(char c);

/**
 * @brief Calculates the checksum for a given zip code.
 *
 * @param zip The zip code as a string.
 * @return std::string A binary string representing the checksum.
 */
std::string checksum(std::string zip);

/**
 * @brief Converts a zip code to its PostNET binary representation.
 *
 * @param zip The zip code as a string.
 * @return std::string The PostNET code, a binary string with a 1 on each end and a checksum.
 */
std::string zipToBits(std::string zip);

/**
 * @brief Formats a given input line and returns its PostNET binary representation.
 *
 * @param line The input line as a string.
 * @return std::string The formatted input line and its PostNET binary representation.
 */
std::string getPostNETOutput(std::string line);
