#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "House.h"
using namespace std;
int main() {
    std::cout << "Projtest" << std::endl;
    ifstream house_file("florida_real_estate.csv");
    string line;
    vector<House> houses_list;
    getline(house_file, line);
    while (getline(house_file, line))
    {
        istringstream iss(line);
        string junk, p, bed, bath, city, zip;
        getline(iss, junk, ',');
        getline(iss, p, ',');
        getline(iss, bed, ',');
        getline(iss, bath, ',');
        getline(iss, city, ',');
        getline(iss, zip, ',');
        int price = std::stoi(p);
        int beds = stoi(bed);
        int baths = stoi(bath);
        auto house = House(price, beds, baths, city, zip);
        houses_list.push_back(house);
    }
    house_file.close();
    cout << "Welcome to Florida Real Estate Listings!" << endl;
    cout << "We have " << houses_list.size() << " houses available." << endl
}