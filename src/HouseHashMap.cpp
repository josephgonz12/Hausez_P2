#include "HouseHashMap.h"
#include <algorithm>
#include <iostream>

HouseHashMap::HouseHashMap(){
    capacity = 101;
    size = 0;
    loadFactorThreshold = 0.75;
    buckets.resize(capacity);
}

HouseHashMap::~HouseHashMap(){
}

int HouseHashMap::hash(const std::string& city) const{
    unsigned long hashValue = 5381;
    for(char c : city){
        hashValue = ((hashValue << 5) + hashValue) + c;
    }
    return hashValue % capacity;
}

void HouseHashMap::resize(){
  int oldCapacity = capacity;
  capacity = capacity * 2 + 1;

  std::vector<Bucket> oldBuckets = buckets;
  buckets.clear();
  buckets.resize(capacity);
  size = 0;

  for(int i = 0; i < oldCapacity; i++){
    for(const House& house : oldBuckets[i].houses){
      insert(house.city, house.price, house.beds, house.baths, house.zip_code);
    }
  }
}

std::vector<House> HouseHashMap::getAllHouses() const {
    std::vector<House> allHouses;
    for (const Bucket& bucket : buckets) {
        for (const House& house : bucket.houses) {
            allHouses.push_back(house);
        }
    }
    return allHouses;
}

void HouseHashMap::insert(std::string city, int price, int beds, int baths, std::string zip_code) {
    float loadFactor = static_cast<float>(size) / capacity;
    if (loadFactor > loadFactorThreshold) {
        resize();
    }
    
    int index = hash(city);
    House newHouse(price, beds, baths, city, zip_code);
    buckets[index].houses.push_back(newHouse);
    size++;
}

std::vector<House> HouseHashMap::getCheapest(int num, int beds, int baths, std::string city, std::string zip_code) {
    std::vector<House> allHouses = getAllHouses();
    
    std::sort(allHouses.begin(), allHouses.end(), [](const House& a, const House& b) {
        return a.price < b.price;
    });
    
    std::vector<House> result;
    
    for (const House& house : allHouses) {
        if (result.size() >= static_cast<size_t>(num)) {
            break;
        }
        
        bool match = true;
        
        if (beds != 0 && house.beds != beds) {
            match = false;
        }
        if (baths != 0 && house.baths != baths) {
            match = false;
        }
        if (city != "" && house.city != city) {
            match = false;
        }
        if (zip_code != "" && house.zip_code != zip_code) {
            match = false;
        }
        
        if (match) {
            result.push_back(house);
        }
    }
    
    return result;
}

std::vector<House> HouseHashMap::filterByCity(std::string city) {
    std::vector<House> result;
    int index = hash(city);
    
    for (const House& house : buckets[index].houses) {
        if (house.city == city) {
            result.push_back(house);
        }
    }
    
    return result;
}

std::vector<House> HouseHashMap::filterByBeds(int bed_count) {
    std::vector<House> result;
    
    for (const Bucket& bucket : buckets) {
        for (const House& house : bucket.houses) {
            if (house.beds == bed_count) {
                result.push_back(house);
            }
        }
    }
    
    return result;
}

std::vector<House> HouseHashMap::filterByBaths(int bath_count) {
    std::vector<House> result;
    
    for (const Bucket& bucket : buckets) {
        for (const House& house : bucket.houses) {
            if (house.baths == bath_count) {
                result.push_back(house);
            }
        }
    }
    
    return result;
}

std::vector<House> HouseHashMap::filterByZip(std::string zip_code) {
    std::vector<House> result;
    
    for (const Bucket& bucket : buckets) {
        for (const House& house : bucket.houses) {
            if (house.zip_code == zip_code) {
                result.push_back(house);
            }
        }
    }
    
    return result;
}