#include "House.h"
#include <vector>

class SkipList {
    struct Node {
        std::vector<Node*> next;

        House house;

        Node(std::string city, int val, int level, int beds, int baths, std::string zip_code) : house(val, beds, baths, city, zip_code) {
            next.resize(level + 1, nullptr);
        }
    };

    int maxLevel;
    double prob;
    Node* head;
    int getRandLevel();

public:
    SkipList();
    ~SkipList();

    void insert(std::string city, int price, int beds, int bath, std::string zip_code);
    std::vector<House> getCheapest(int num);
    std::vector<House> filterByCity(std::string city);
    void display();

};