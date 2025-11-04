#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "House.h"
#include "SkipList.h"
using namespace std;
int main() {
    std::cout << "Welcome to Florida Real Estate!" << std::endl;
    ifstream house_file("../florida_real_estate.csv");
    string line;
    vector<House> houses;
    getline(house_file, line);
    SkipList Skip;
     int bed_filter, bath_filter, zip_filter = 0;
    string city_filter = "";
    bool running = true;
    
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
        Skip.insert(city, stoi(price), stoi(bed), stoi(bath), stoi(zip_code));
    }
    while (running) {
        std::cout <<"There are " << houses.size() << " houses available." << std::endl;
        std::cout << "Current Filters: " << std::endl;
        std::cout << "City: " << (city_filter == "" ? "None" : city_filter) << std::endl;
        std::cout << "Beds: " << (bed_filter == 0 ? "Any" : to_string(bed_filter)) << std::endl;
        std::cout << "Baths: " << (bath_filter == 0 ? "Any" : to_string(bath_filter)) << std::endl;
        std::cout << "Zip Code: " << (zip_filter == 0 ? "Any" : to_string(zip_filter)) << std::endl;    
        std::cout << "0: Exit" << std::endl;
        std::cout << "1: Set City" << std::endl;
        std::cout << "2: Set Beds" << std::endl;
        std::cout << "3: Set Baths" << std::endl;
        std::cout << "4: Set Zip Code" << std::endl;
        std::cout << "5: View Top 5 Cheapest Houses" << std::endl;
        std::cout << "Select an option: ";
        int option;
        std::cin >> option;
        if (option == 0){running = false;}
        if (option == 1){
            std::cout << "Enter City Name: ";
            std::cin >> city_filter;
        }
        if (option == 2){
            std::cout << "Enter Number of Beds: ";
            std::cin >> bed_filter;
        }
        if (option == 3){
            std::cout << "Enter Number of Baths: ";
            std::cin >> bath_filter;
        }
        if (option == 4){
            std::cout << "Enter Zip Code: ";
            std::cin >> zip_filter;
        }
        if (option == 5){
            auto cheapestHouses = Skip.getCheapest(5);
            for (const auto& house : cheapestHouses) {
                std::cout << "Price: " << house.price << ", Beds: " << house.beds << ", Baths: " << house.baths << ", City: " << house.city << ", Zip Code: " << house.zip_code << std::endl;
            }
        }
    }
}