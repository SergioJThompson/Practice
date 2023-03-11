#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H

#include <string>

/**
 * Retrieves the contents of a file as a vector of strings,
 * excluding the first line (assumed to be a header).
 *
 * @param filename The name of the file to read.
 *
 * @return A vector of strings, each element representing a row in the CSV file.
 */
std::vector<std::string> get_file_contents_as_strings(std::string filename);

/**
 * Prints the first and last three elements in a string vector.
 *
 * @param lines The string vector.
 */
void print_first_three_last_three(std::vector<std::string> lines);

#endif // DATABASEFUNCTIONS_H
