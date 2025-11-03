#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "House.h"
using namespace std;
int main() {
    std::cout << "Proj2" << std::endl;
    ifstream house_file("florida_real_estate.csv");
    string line;
    vector<House> houses;
    getline(house_file, line);
    while (getline(house_file, line))
    {
        istringstream iss(line);
        string junk, price, bed, bath, city, zip_code, square_feet;
        getline(iss, junk, ',');
        getline(iss, price, ',');
        getline(iss, bed, ',');
        getline(iss, bath, ',');
        getline(iss, city, ',');
        getline(iss, zip_code, ',');
        getline(iss, square_feet, ',');


    }
}