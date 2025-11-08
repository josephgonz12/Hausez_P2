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
    std::vector<House> getCheapest(int num, int beds = 0, int baths = 0, std::string city = "", std::string zip_code = "");
    std::vector<House> filterByCity(std::string city);
    std::vector<House> filterByBeds(int bed_count);
    std::vector<House> filterByBaths(int bath_count);
    std::vector<House> filterByZip(std::string zip_code);
    void display();

};