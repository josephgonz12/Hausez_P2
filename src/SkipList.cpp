#include "SkipList.h"
#include <cstdlib>
#include <ctime>

int SkipList::getRandLevel(int maxLevel) {
    int level = 0;

    while (rand() % 2 == 1 && level < maxLevel) {
        level++;
    }
    return level;
}

void SkipList::insert(std::string state, int price){

}

std::vector<House> SkipList::getCheapest(int num) {

}

std::vector<House> SkipList::filterByState(std::string state) {

}

void SkipList::display() {
    
}



