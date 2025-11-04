#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "House.h"
using namespace std;
int main() {
    std::cout << "Welcome to Florida Real Estate!" << std::endl;
    ifstream house_file("../florida_real_estate.csv");
    string line;
    vector<House> houses;
    getline(house_file, line);
    while (getline(house_file, line))
    {
        istringstream iss(line);
        string junk, price, bed, bath, city, state, zip_code, square_feet;
        getline(iss, junk, ',');
        getline(iss, price, ',');
        getline(iss, bed, ',');
        getline(iss, bath, ',');
        getline(iss, city, ',');
        city.erase(std::remove(city.begin(), city.end(), '\"'), city.end());
        getline(iss, state, ',');
        getline(iss, zip_code, ',');
        zip_code.erase(std::remove(zip_code.begin(), zip_code.end(), '\"'), zip_code.end());
        getline(iss, square_feet, ',');
        House temp = House(stoi(price), stoi(bed), stoi(bath), city, stoi(zip_code));
        houses.push_back(temp);
    }
   
    std::cout <<"There are " << houses.size() << " houses available." << std::endl;
   
    int num;
    std::cin >> num;
}