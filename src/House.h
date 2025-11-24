#pragma once
#include <iostream>
using namespace std;
struct House {
    int price;
    int beds;
    int baths;
    std::string city;
    std::string zip_code;
    

    House(int price, int beds, int baths, std::string city, std::string zip_code);
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;
    
};