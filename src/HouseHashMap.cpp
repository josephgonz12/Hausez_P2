//
// Created by Lee Guercin on 11/3/25.
//
#include "HouseHashMap.h"

HouseHashMap::HouseHashMap() {

}

// Add a house to the map
void HouseHashMap::insert(const House& house){
  cityMap[house.state].push_back(house);

}

// Get all houses in a specific city
std::vector<House> HouseHashMap::getHousesByCity(const std::string& city){
  if (cityMap.find(city) != cityMap.end()){
    return cityMap[city];
    }
    return {}; // Return empty vector if city not found
}

// Get cheapest houses in a city (sorted by price)
std::vector<House> HouseHashMap::getCheapesHouses(const std::string &city, int count){
  std::vector<House> houses = getHousesByCity(city);
    
    if (houses.empty()) {
        return {};
    }
    
    // Sort by price (ascending)
    std::sort(houses.begin(), houses.end());
    
    // Return only first 'count' elements
    if (houses.size() > static_cast<size_t>(count)) {
        return std::vector<House>(houses.begin(), houses.begin() + count);  // ← Changed this line
    }
    
    return houses;
}

// Check if a city exist in the map
bool HouseHashMap::hasCity(const std::string &city)
{
  return cityMap.find(city) != cityMap.end();
}

// Get all available cityes
std::vector<std::string> HouseHashMap::getAllCities()
{
  std::vector<std::string> cities;
  for(const auto& pair : cityMap){
    cities.push_back(pair.first);
  }
    return cities;
}

// Get total number of houses in a city
int HouseHashMap::getHouseCount(const std::string &city)
{
  if(hasCity(city)){
    return cityMap[city].size();
  }
    return 0;
}

//Clear all data
void HouseHashMap::clear(){
  cityMap.clear();
}

