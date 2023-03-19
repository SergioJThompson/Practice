/**
* @brief Assignment 9
* @name Sergio Thompson
*/

#include "databaseFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Album {
    int rank;
    std::string title;
    std::string artist;
    std::string country;
    int year;
    double avg_rating;
    int num_ratings;
};

int main() {
    std::vector<std::string> lines = get_file_contents_as_strings("best-ever-albums-ranked.csv");
    std::vector<Album> albums = lines_to_albums(lines);
    std::vector<Album> oldest_albums = find_oldest(albums);
    std::vector<Album> newest_albums = find_newest(albums);
    std::vector<Album> albums_with_most_ratings = find_most_ratings(albums);
    std::vector<Album> albums_with_fewest_ratings = find_fewest_ratings(albums);
    double avg_rating = calc_avg_rating(albums);
    int avg_num_ratings = calc_avg_num_ratings(albums);
    std::vector<Album> albums_before_1965_after_1999 = find_albums_before_1965_after_1999(albums);
    std::vector<Album> albums_not_us_uk_ca = find_albums_not_us_uk_ca(albums);

    std::cout << std::endl << "First three lines:" << std::endl << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << lines[i] << std::endl;
    }

    std::cout << std::endl << "Last three lines:" << std::endl << std::endl;
    int lines_size = lines.size();
    for (int i = lines_size - 3; i < lines_size; i++) {
        std::cout << lines[i] << std::endl;
    }

    std::cout << std::endl << "Oldest album(s):" << std::endl << std::endl;
    int oldest_albums_size = oldest_albums.size();
    for (int i = 0; i < oldest_albums_size; i++) {
        std::cout << oldest_albums[i].artist << " - " << oldest_albums[i].title << " (" << oldest_albums[i].year << ")" << std::endl;
    }

    std::cout << std::endl << "Newest album(s):" << std::endl << std::endl;
    int newest_albums_size = newest_albums.size();
    for (int i = 0; i < newest_albums_size; i++) {
        std::cout << newest_albums[i].artist << " - " << newest_albums[i].title << " (" << newest_albums[i].year << ")" << std::endl;
    }

    std::cout << std::endl << "Album(s) with most ratings:" << std::endl << std::endl;
    int albums_with_most_ratings_size = albums_with_most_ratings.size();
    for (int i = 0; i < albums_with_most_ratings_size; i++) {

        std::cout << albums_with_most_ratings[i].artist << " - " << albums_with_most_ratings[i].title << " (" << albums_with_most_ratings[i].num_ratings << ")" << std::endl;
    }

    std::cout << std::endl << "Album(s) with fewest ratings:" << std::endl << std::endl;
    int albums_with_fewest_ratings_size = albums_with_fewest_ratings.size();
    for (int i = 0; i < albums_with_fewest_ratings_size; i++) {
        std::cout << albums_with_fewest_ratings[i].artist << " - " << albums_with_fewest_ratings[i].title << " (" << albums_with_fewest_ratings[i].num_ratings << ")" << std::endl;
    }

    std::cout << std::endl << "Average rating across all albums:" << std::endl << std::endl;
    std::cout << avg_rating << std::endl;

    std::cout << std::endl << "Average number of ratings:" << std::endl << std::endl;
    std::cout << avg_num_ratings << std::endl;

    std::cout << std::endl << "Albums released before 1965 or after 1999:" << std::endl << std::endl;
    int albums_1965_1999_size = albums_before_1965_after_1999.size();
    for (int i = 0; i < albums_1965_1999_size; i++) {
        std::cout << albums_before_1965_after_1999[i].artist << " - " << albums_before_1965_after_1999[i].title << " (" << albums_before_1965_after_1999[i].year << ")" << std::endl;
    }

    std::cout << std::endl << "Albums not American, British, or Canadian:" << std::endl << std::endl;
    int not_us_uk_ca_size = albums_not_us_uk_ca.size();
    for (int i = 0; i < not_us_uk_ca_size; i++) {
        std::cout << albums_not_us_uk_ca[i].artist << " - " << albums_not_us_uk_ca[i].title << " (" << albums_not_us_uk_ca[i].country << ")" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
