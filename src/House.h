#include <string>
#include <iostream>

struct House {
    std::string state;
    int price;

    House(std::string state, int p);
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;
    
};