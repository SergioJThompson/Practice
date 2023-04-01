/**
* @brief Assignment 2
* @name Sergio Thompson
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> intersect(vector<int> v1, vector<int> v2) {
    vector<int> intersection;
    int min = std::min(v1.size(), v2.size());
    for (int i = 0; i < min; i++) {
        for (int j = 0; j < min; j++) {
            if (v1[i] == v2[j]) {
                intersection.push_back(v1[i]);
                continue;
            }
        }
    }
    return intersection;
}

int main() {

}
