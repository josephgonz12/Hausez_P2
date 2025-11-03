#include <string>
#include <iostream>

struct House {
    int price;
    int beds;
    int baths;
    string city;
    int zip_code;
    int square_feet;


    House(int price, int beds, int baths, string city, int zip_code, int square_feet);
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;
    
};