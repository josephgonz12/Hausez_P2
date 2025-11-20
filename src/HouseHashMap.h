#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "House.h"


class HouseHashMap{
  private:
    struct Bucket{
      std::vector<House> houses;
    };

    std::vector<Bucket> buckets;
    int capacity;
    int size;
    float loadFactorThreshold;

    int hash(const std::string& city) const;

    void resize();

    std::vector<House> getAllHouses() const;

  public:
    HouseHashMap();
    ~HouseHashMap();

    void insert(std::string city, int price, int beds, int baths, std::string zip_code);
    std::vector<House> getCheapest(int num, int beds = 0, int baths = 0, std::string city = "", std::string zip_code = "");
    std::vector<House> filterByCity(std::string city);
    std::vector<House> filterByBeds(int bed_count);
    std::vector<House> filterByBaths(int bath_count);
    std::vector<House> filterByZip(std::string zip_code);
};
