#include "SkipList.h"
#include <random>

SkipList::SkipList() {
    maxLevel = 0;
    prob = 0.5;
    const int maxSize = 16;
    head = new Node("dummy", -1, maxSize, 0, 0, "0");
}

SkipList::~SkipList() {
    Node* curr = head->next[0];
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next[0];
        delete temp;
    }
    delete head;
}

int SkipList::getRandLevel() {
    int level = 0;
    int maxSize = head->next.size() - 1;

    while ((rand() / (double)RAND_MAX) < prob && level < maxSize) {
        level++;
    }
    return level;
}


void SkipList::insert(std::string state, int price, int beds, int bath, std::string zip_code){
    std::vector<Node*> update(head->next.size(), nullptr);
    Node* curr = head;

    for (int i = maxLevel; i >= 0; i--) {
        while (curr->next[i] != nullptr && curr->next[i]->house.price < price) {
            curr = curr->next[i];
        }
        update[i] = curr;
    }

    
    int nextLevel = getRandLevel();

    if (nextLevel > maxLevel) {
        for (int i = maxLevel + 1; i <= nextLevel; i++) {
            update[i] = head;
        }
        maxLevel = nextLevel;
    }

    Node* newNode = new Node(state, price, nextLevel, beds, bath, zip_code);

    for (int i = 0; i <= nextLevel; i++) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }

}

std::vector<House> SkipList::getCheapest(int num) {
    std::vector<House> cheapestHouses;
    Node* curr = head->next[0];
    for (int i = 0; i < num; i++) {
        cheapestHouses.push_back(curr->house);
        curr = curr->next[0];
    }
    return cheapestHouses;
}

std::vector<House> SkipList::filterByCity(std::string city) {
    std::vector<House> byCity;
    Node* curr = head->next[0];
    while (curr != nullptr) {
        if (curr->house.city == city) {
            byCity.push_back(curr->house);
        }
        curr = curr->next[0];
    }
    return byCity;
}
std::vector<House> SkipList::filterByBeds(int bed_count) {
    std::vector<House> byBeds;
    Node* curr = head->next[0];
    while (curr != nullptr) {
        if (curr->house.beds == bed_count) {
            byBeds.push_back(curr->house);
        }
        curr = curr->next[0];
    }
    return byBeds;
}

std::vector<House> SkipList::filterByBaths(int bath_count) {
    std::vector<House> byBaths;
    Node* curr = head->next[0];
    while (curr != nullptr) {
        if (curr->house.baths == bath_count) {
            byBaths.push_back(curr->house);
        }
        curr = curr->next[0];
    }
    return byBaths;
}

std::vector<House> SkipList::filterByZip(string zip_code) {
    std::vector<House> byZip;
    Node* curr = head->next[0];
    while (curr != nullptr) {
        if (curr->house.zip_code == zip_code) {
            byZip.push_back(curr->house);
        }
        curr = curr->next[0];
    }
    return byZip;
}

void SkipList::display() {
    for (int i = maxLevel; i >= 0; i--) {
        std::cout << "Level " << i << ": Head-> ";
        Node* curr = head->next[i];
        while (curr != nullptr) {
            std::cout << "(" << curr->house.city << ", " << curr->house.price << ") -> ";
            curr = curr->next[i];
        }
        std::cout << "" << std::endl;
    }
    std::cout << "-------------" << std::endl;
}



