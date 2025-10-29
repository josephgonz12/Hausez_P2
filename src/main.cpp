#include <iostream>
#include <string>
#include "House.h"

int main() {
    std::cout << "Proj2" << std::endl;
    House testHouse = House("Florida", 120000);
    std::cout << testHouse.price << std::endl;
    return 0;
}