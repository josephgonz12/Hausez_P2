#include <string>
using namespace std;
House::House(int price, int beds, int baths, string city, int zip_code, int square_feet)
{
    this->price = price;
    this->beds = beds;
    this->baths = baths;
    this->city = city;
    this->zip_code = zip_code;
    this->square_feet = square_feet;
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