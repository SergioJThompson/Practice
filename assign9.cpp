#include "databaseFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Pieces {
    int rank;
    string title;
    string artist;
    string country;
    int year;
    double avg_rating;
    int num_ratings;
};

int main() {
    std::vector<std::string> lines = get_file_contents_as_strings("best-ever-albums-ranked.csv");
    print_first_three_last_three(lines);
    return 0;
}
