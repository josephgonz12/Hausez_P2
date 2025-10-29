#include "House.h"

House::House(std::string state, int price) {
    this->state = state;
    this->price = price;
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