#include "House.h"
#include <vector>

class SkipList {
    struct Node {
        std::vector<Node*> next;

        House house;

        Node(std::string state, int val, int level) : house(state, val) {
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

    void insert(std::string state, int price);
    std::vector<House> getCheapest(int num);
    std::vector<House> filterByState(std::string state);
    void display();

};