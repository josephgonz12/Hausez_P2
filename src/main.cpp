#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "House.h"
#include "SkipList.h"
#include <stdlib.h>
using namespace std;
int main() {
    std::cout << "Welcome to Florida Real Estate!" << std::endl;
    ifstream house_file("../florida_real_estate.csv");
    string line;
    vector<House> houses_list;
    // SkipList skiplist;
    getline(house_file, line);
    getline(house_file, line);
    SkipList Skip;
    int bed_filter;
    int bath_filter;
    int zip_filter;
    string city_filter = "";
    bool running = true;
    
    while (getline(house_file, line))
    {
        istringstream iss(line);
        string junk, price, bed, bath, city, state, zip_code, square_feet;
        getline(iss, junk, ',');
        getline(iss, price, ',');
        double val = stod(price);
        price = to_string(static_cast<int>(val));
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
    bed_filter = 0;
    bath_filter = 0;
    zip_filter = 0;
    while (running) {
        std::cout <<"There are " << houses.size() << " houses available." << std::endl;
        std::cout << "Current Filters: " << std::endl;
        std::cout << "City: " << (city_filter == "" ? "Any City" : city_filter) << std::endl;
        std::cout << "Beds: " << (bed_filter == 0 ? "Any" : to_string(bed_filter)) << std::endl;
        std::cout << "Baths: " << (bath_filter == 0 ? "Any" : to_string(bath_filter)) << std::endl;
        std::cout << "Zip Code: " << (zip_filter == 0 ? "Any" : to_string(zip_filter)) << std::endl;    
        std::cout << "1: Set City" << std::endl;
        std::cout << "2: Set Beds" << std::endl;
        std::cout << "3: Set Baths" << std::endl;
        std::cout << "4: Set Zip Code" << std::endl;
        std::cout << "5: View Top 5 Cheapest Houses" << std::endl;
        std::cout << "6: Exit" << std::endl;
        std::cout << "Select an option: ";
        int option;
        std::cin >> option;
     
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
            std::cout << "Which data structure would you like to use?" << std::endl;
            std::cout << "1: Skip List" << std::endl;
            std::cout << "2: Heap" << std::endl;
            int ds_option;
            std::cin >> ds_option;
            if (ds_option == 1){
                auto cheapest = Skip.getCheapest(5);
                std::cout << "Top 5 Cheapest Houses:" << std::endl;
                cout << "House 1: Price: $" << cheapest[0].price << ", Beds: " << cheapest[0].beds << ", Baths: " << cheapest[0].baths << ", City: " << cheapest[0].city << ", Zip Code: " << cheapest[0].zip_code << endl;
                cout << "House 2: Price: $" << cheapest[1].price << ", Beds: " << cheapest[1].beds << ", Baths: " << cheapest[1].baths << ", City: " << cheapest[1].city << ", Zip Code: " << cheapest[1].zip_code << endl;
                cout << "House 3: Price: $" << cheapest[2].price << ", Beds: " << cheapest[2].beds << ", Baths: " << cheapest[2].baths << ", City: " << cheapest[2].city << ", Zip Code: " << cheapest[2].zip_code << endl;
                cout << "House 4: Price: $" << cheapest[3].price << ", Beds: " << cheapest[3].beds << ", Baths: " << cheapest[3].baths << ", City: " << cheapest[3].city << ", Zip Code: " << cheapest[3].zip_code << endl;
                cout << "House 5: Price: $" << cheapest[4].price << ", Beds: " << cheapest[4].beds << ", Baths: " << cheapest[4].baths << ", City: " << cheapest[4].city << ", Zip Code: " << cheapest[4].zip_code << endl;
            }
            cout << "1: Go Back to Main Menu" << endl;
            int back_option;
            std::cin >> back_option;
            system("cls");
            
        }
        if (option == 6){
            
            running = false;
        }
        option = 0;
    }
    return 0;
}