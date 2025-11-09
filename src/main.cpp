#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "House.h"
#include "SkipList.h"
#include "HouseHashMap.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Welcome to Florida Real Estate!" << std::endl;
    ifstream house_file("florida_real_estate.csv");
    string line;
    vector<House> houses;
    getline(house_file, line);
    SkipList Skip;
    HouseHashMap HouseMap;
    int bed_filter;
    int bath_filter;
    string zip_filter = "";
    string city_filter = "";
    bool running = true;
    std::chrono::steady_clock::duration skiplist_insert_total_duration{};
    std::chrono::steady_clock::duration hashmap_insert_total_duration{};
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
        House temp = House(stoi(price), stoi(bed), stoi(bath), city, zip_code);
        houses.push_back(temp);
        auto map_start = std::chrono::steady_clock::now();
        HouseMap.insert(temp);
        auto map_end = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration map_insert_duration = map_end - map_start;
        auto skip_start = std::chrono::steady_clock::now();
        Skip.insert(city, stoi(price), stoi(bed), stoi(bath), zip_code);
        auto skip_end = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration skip_insert_duration = skip_end - skip_start;
        skiplist_insert_total_duration += skip_insert_duration;
        hashmap_insert_total_duration += map_insert_duration;
    }
    auto total_skip__ms = std::chrono::duration_cast<std::chrono::milliseconds>(skiplist_insert_total_duration).count();
    auto total_map__ms = std::chrono::duration_cast<std::chrono::milliseconds>(hashmap_insert_total_duration).count();
    bed_filter = 0;
    bath_filter = 0;
    zip_filter = "";
    std::cout <<"There are " << houses.size() << " houses available." << std::endl;
    std::cout << "Total time to insert houses into Skip List: " << total_skip__ms << " ms" << std::endl;
    std::cout << "Total time to insert houses into Hash Map: " << total_map__ms << " ms" << std::endl;
    while (running) {
        
        std::cout << "Current Filters: " << std::endl;
        std::cout << "City: " << (city_filter == "" ? "Any City" : city_filter) << std::endl;
        std::cout << "Beds: " << (bed_filter == 0 ? "Any" : to_string(bed_filter)) << std::endl;
        std::cout << "Baths: " << (bath_filter == 0 ? "Any" : to_string(bath_filter)) << std::endl;
        std::cout << "Zip Code: " << (zip_filter == "" ? "Any" : zip_filter) << std::endl;    
        std::cout << "1: Set City" << std::endl;
        std::cout << "2: Set Beds" << std::endl;
        std::cout << "3: Set Baths" << std::endl;
        std::cout << "4: Set Zip Code" << std::endl;
        std::cout << "5: View Cheapest Houses With Filter" << std::endl;
        std::cout << "6: Exit" << std::endl;
        std::cout << "Select an option: ";
        int option;
        std::cin >> option;
     
        if (option == 1){
            std::cout << "Enter City Name: ";
            std::cin >> city_filter;
            system("cls");
        }
        if (option == 2){
            std::cout << "Enter Number of Beds: ";
            std::cin >> bed_filter;
            system("cls");
        }
        if (option == 3){
            std::cout << "Enter Number of Baths: ";
            std::cin >> bath_filter;
            system("cls");
        }
        if (option == 4){
            std::cout << "Enter Zip Code: ";
            std::cin >> zip_filter;
            system("cls");
        }
        if (option == 5){
            int house_num;
            std::cout << "Enter the number of houses to view: ";
            std::cin >> house_num;
            std::cout << "Which data structure would you like to use?" << std::endl;
            std::cout << "1: Skip List" << std::endl;
            std::cout << "2: Hash Map" << std::endl;
            std::cout << "Select an option: ";
            int ds_option;
            std::cin >> ds_option;
            if (ds_option == 1){
                auto start = std::chrono::steady_clock::now();
                auto cheapest = Skip.getCheapest(house_num, bed_filter, bath_filter, city_filter, zip_filter);
                auto end = std::chrono::steady_clock::now();
                std::chrono::steady_clock::duration query_duration = end - start;
                auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(query_duration).count();
                system("cls");
                if (cheapest.empty()) {
                    std::cout << "No houses found! Try changing your filters!" << std::endl;
                }
                else {
                    std::cout << "Top " << house_num << " Cheapest Houses:" << std::endl;
                    for (size_t i = 0; i < cheapest.size(); i++) {
                        cout << "House " << (i + 1) << ": Price: $" << cheapest[i].price << ", Beds: " << cheapest[i].beds << ", Baths: " << cheapest[i].baths << ", City: " << cheapest[i].city << ", Zip Code: " << cheapest[i].zip_code << endl;
                    }
                }
                std::cout << "Time taken to fetch houses using Skip List: " << total_ms << " ms" << std::endl;
            }
            if (ds_option == 2){
                auto start = std::chrono::steady_clock::now();
                auto cheapest = HouseMap.getCheapestHouses(city_filter, house_num, bed_filter, bath_filter, zip_filter);
                auto end = std::chrono::steady_clock::now();
                std::chrono::steady_clock::duration query_duration = end - start;
                auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(query_duration).count();
                system("cls");
                if (cheapest.empty()) {
                    std::cout << "No houses found! Try changing your filters" << std::endl;
                }
                else {
                    std::cout << "Top " << house_num << " Cheapest Houses:" << std::endl;
                    for (size_t i = 0; i < cheapest.size(); i++) {
                        cout << "House " << (i + 1) << ": Price: $" << cheapest[i].price << ", Beds: " << cheapest[i].beds << ", Baths: " << cheapest[i].baths << ", City: " << cheapest[i].city << ", Zip Code: " << cheapest[i].zip_code << endl;
                    }
                }
                std::cout << "Time taken to fetch houses using Hash Map: " << total_ms << " ms" << std::endl;
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