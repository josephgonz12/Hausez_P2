#pragma once
#include <iostream>
using namespace std;
struct House {
    int price;
    int beds;
    int baths;
    std::string city;
    int zip_code;
    int square_feet;


    House(int price, int beds, int baths, std::string city, int zip_code, int square_feet);
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;
    
};