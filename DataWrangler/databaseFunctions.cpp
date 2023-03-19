/**
* @brief Assignment 9
* @name Sergio Thompson
*/

#include "databaseFunctions.h"

#include <fstream>
#include <iostream>
#include <sstream>
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

Album line_to_album(std::string line) {
    Album pieces;

    std::stringstream ss(line);
    std::string field;

    std::getline(ss >> pieces.rank, field, ',');
    std::getline(ss >> std::ws, pieces.title, ',');
    std::getline(ss, pieces.artist, ',');
    std::getline(ss, pieces.country, ',');
    std::getline(ss >> pieces.year, field, ',');
    std::getline(ss >> pieces.avg_rating, field, ',');
    std::getline(ss >> pieces.num_ratings, field, ',');

    return pieces;
}

std::vector<Album> lines_to_albums(std::vector<std::string> lines) {
    std::vector<Album> albums;
    int num_lines = lines.size();
    for (int i = 0; i < num_lines; i++) {
        Album album = line_to_album(lines[i]);
        albums.push_back(album);
    }
    return albums;
}

std::vector<Album> find_oldest(std::vector<Album> albums) {
    int num_albums = albums.size();

    int oldest_year = albums[0].year;
    for (int i = 1; i < num_albums; i++) {
        int this_year = albums[i].year;
        if (this_year < oldest_year) {
            oldest_year = this_year;
        }
    }

    std::vector<Album> oldest_albums;
    for (int i = 0; i < num_albums; i++) {
        int this_year = albums[i].year;
        if (this_year == oldest_year) {
            oldest_albums.push_back(albums[i]);
        }
    }

    return oldest_albums;
}

std::vector<Album> find_newest(std::vector<Album> albums) {
    int num_albums = albums.size();

    int newest_year = albums[0].year;
    for (int i = 1; i < num_albums; i++) {
        int this_year = albums[i].year;
        if (this_year > newest_year) {
            newest_year = this_year;
        }
    }

    std::vector<Album> newest_albums;
    for (int i = 0; i < num_albums; i++) {
        int this_year = albums[i].year;
        if (this_year == newest_year) {
            newest_albums.push_back(albums[i]);
        }
    }

    return newest_albums;
}

std::vector<Album> find_most_ratings(std::vector<Album> albums) {
    int num_albums = albums.size();

    int most_ratings = albums[0].num_ratings;
    for (int i = 1; i < num_albums; i++) {
        int this_num_ratings = albums[i].num_ratings;
        if (this_num_ratings > most_ratings) {
            most_ratings = this_num_ratings;
        }
    }

    std::vector<Album> most_rated_albums;
    for (int i = 0; i < num_albums; i++) {
        int this_num_ratings = albums[i].num_ratings;
        if (this_num_ratings == most_ratings) {
            most_rated_albums.push_back(albums[i]);
        }
    }

    return most_rated_albums;
}

std::vector<Album> find_fewest_ratings(std::vector<Album> albums) {
    int num_albums = albums.size();

    int fewest_ratings = albums[0].num_ratings;
    for (int i = 1; i < num_albums; i++) {
        int this_num_ratings = albums[i].num_ratings;
        if (this_num_ratings < fewest_ratings) {
            fewest_ratings = this_num_ratings;
        }
    }

    std::vector<Album> least_rated_albums;
    for (int i = 0; i < num_albums; i++) {
        int this_num_ratings = albums[i].num_ratings;
        if (this_num_ratings == fewest_ratings) {
            least_rated_albums.push_back(albums[i]);
        }
    }

    return least_rated_albums;
}

double calc_avg_rating(std::vector<Album> albums) {
    double sum = 0;
    int count = 0;
    int albums_size = albums.size();
    for (int i = 0; i < albums_size; i++) {
        Album album = albums[i];
        sum += album.avg_rating;
        count++;
    }
    return sum / count;
}

int calc_avg_num_ratings(std::vector<Album> albums) {
    int sum = 0;
    int count = 0;
    int albums_size = albums.size();
    for (int i = 0; i < albums_size; i++) {
        Album album = albums[i];
        sum += album.num_ratings;
        count++;
    }
    return sum / count;
}

std::vector<Album> find_albums_before_1965_after_1999(std::vector<Album> albums) {
    std::vector<Album> albums_to_return;
    int albums_size = albums.size();
    for (int i = 0; i < albums_size; i++) {
        Album album = albums[i];
        if (album.year < 1965 || album.year > 1999) {
            albums_to_return.push_back(album);
        }
    }
    return albums_to_return;
}

std::vector<Album> find_albums_not_us_uk_ca(std::vector<Album> albums) {
    std::vector<Album> albums_to_return;
    int albums_size = albums.size();
    for (int i = 0; i < albums_size; i++) {
        Album album = albums[i];
        if (album.country != "us" && album.country != "uk" && album.country != "ca") {
            albums_to_return.push_back(album);
        }
    }
    return albums_to_return;
}
