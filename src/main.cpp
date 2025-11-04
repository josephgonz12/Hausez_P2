#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "House.h"
#include "SkipList.h"
using namespace std;
int main() {
    std::cout << "Project 2trass" << std::endl;
    ifstream house_file("florida_real_estate.csv");
    string line;
    vector<House> houses_list;
    // SkipList skiplist;
    getline(house_file, line);
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
        cout << baths << endl;
        auto house = House(price, beds, baths, city, zip);
        // skiplist.insert(city, price, beds, baths, zip);
        houses_list.push_back(house);

    }
   
    cout << "Welcome to Florida Real Estate Listings!" << endl;
    cout << "We have " << houses_list.size() << " houses available." << endl;
   
    return 0;
}