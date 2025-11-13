#include <string>
#include "House.h"
using namespace std;
House::House(int price, int beds, int baths, std::string city, std::string zip_code)
{
    this->price = price;
    this->beds = beds;
    this->baths = baths;
    this->city = city;
    this->zip_code = zip_code;
}

bool House::operator<(const House& other) const {
        return price < other.price;
}

bool House::operator>(const House& other) const {
        return price > other.price;
}

bool House::operator==(const House& other) const {
        return price == other.price;
}