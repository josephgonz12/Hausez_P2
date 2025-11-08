//
// Created by Lee Guercin on 11/2/25.
//

#ifndef HOUSEHASHMAP_H
#define HOUSEHASHMAP_H

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "House.h"


class HouseHashMap{
  private:
    std::unordered_map<std::string, std::vector<House>> cityMap;

  public:
      HouseHashMap();
      
      void insert(const House& house);

      std::vector<House> getHousesByCity(const std::string& city);

      std::vector<House> getCheapesHouses(const std::string &city, int count = 10);

      bool hasCity(const std::string& city);

      std::vector<std::string> getAllCities();

      int getHouseCount(const std::string& city);

      void clear(); 
};
#endif //HOUSEHASHMAP_H