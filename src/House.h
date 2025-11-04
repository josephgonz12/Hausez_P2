#pragma once
#include <iostream>
using namespace std;
struct House {
    int price;
    int beds;
    int baths;
    std::string city;
    int zip_code;
    string toos;

    House(int price, int beds, int baths, std::string city, int zip_code);
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;
    
};