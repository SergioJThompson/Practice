/**
* @brief Assignment 9
* @name Sergio Thompson
*/

#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H

#include <string>

struct Album;

/**
 * Retrieves the contents of a file as a vector of strings,
 * excluding the first line (assumed to be a header).
 *
 * @param filename The name of the file to read.
 *
 * @return A vector of strings, each element representing a row in the file.
 */
std::vector<std::string> get_file_contents_as_strings(std::string filename);

/**
 * Parses a CSV line into an Album struct.
 *
 * @param line A string representing a line of data in CSV format.
 * @return An Album struct containing the parsed data.
 */
Album line_to_album(std::string line);

/**
 * Parses a vector of CSV lines into a vector of Album structs.
 *
 * @param lines A vector of strings representing lines of data in CSV format.
 * @return A vector of Album structs containing the parsed data.
 */
std::vector<Album> lines_to_albums(std::vector<std::string> lines);

/**
 * Finds the oldest album(s), i.e. the one(s) with the earliest year, from a vector of albums.
 * @param albums The vector of albums to search.
 * @return A vector containing the oldest album(s).
 */
std::vector<Album> find_oldest(std::vector<Album> albums);

/**
 * Finds the newest album(s), i.e. the one(s) with the latest year, from a vector of albums.
 * @param albums The vector of albums to search.
 * @return A vector containing the newest album(s).
 */
std::vector<Album> find_newest(std::vector<Album> albums);

/**
 * Finds the album(s) with the highest number of ratings from a vector of albums.
 * @param albums The vector of albums to search.
 * @return A vector containing the most-rated album(s).
 */
std::vector<Album> find_most_ratings(std::vector<Album> albums);

/**
 * Finds the album(s) with the lowest number of ratings from a vector of albums.
 * @param albums The vector of albums to search.
 * @return A vector containing the album(s) with the fewest ratings.
 */
std::vector<Album> find_fewest_ratings(std::vector<Album> albums);

/**
 * Calculates the average of all average ratings for a given vector of albums.
 *
 * @param albums A vector of Album objects to calculate the average rating for.
 * @return The average rating across all the albums.
 */
double calc_avg_rating(std::vector<Album> albums);

/**
 * Calculates the average number of ratings for a given vector of albums.
 *
 * @param albums A vector of Album objects to calculate the average number of rating for.
 * @return The average number of ratings across all the albums.
 */
int calc_avg_num_ratings(std::vector<Album> albums);

/**
 * Finds the albums with a year earlier than 1965 or later than 1999 from a vector of albums.
 * @param albums The vector of albums to search.
 * @return A vector containing the album(s) before 1965 and/or after 1999.
 */
std::vector<Album> find_albums_before_1965_after_1999(std::vector<Album> albums);

/**
 * Finds the albums from a country other than the US, the UK, or Canada.
 * @param albums The vector of albums to search.
 * @return A vector containing the album(s) from elsewhere than the US, the UK, or Canada.
 */
std::vector<Album> find_albums_not_us_uk_ca(std::vector<Album> albums);

#endif // DATABASEFUNCTIONS_H
