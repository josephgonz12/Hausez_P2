//
// Created by Lee Guercin on 11/3/25.
//
#include "HouseHashMap.h"

HouseHashMap::HouseHashMap() {

}

// Add a house to the map
void HouseHashMap::insert(const House& house){
  cityMap[house.city].push_back(house);

}

// Get all houses in a specific city
std::vector<House> HouseHashMap::getHousesByCity(const std::string& city){
  if (city == ""){
    std::vector<House> allHouses;
    for (const auto& pair : cityMap) {
        allHouses.insert(allHouses.end(), pair.second.begin(), pair.second.end());
    }
    return allHouses;
  }
  if (cityMap.find(city) != cityMap.end()){
    return cityMap[city];
    }
    return {}; // Return empty vector if city not found
}

// Get cheapest houses in a city (sorted by price) with optional filters
std::vector<House> HouseHashMap::getCheapestHouses(const std::string &city, int count, int beds, int baths, std::string zip_code){
  // Get all houses for the city
  std::vector<House> houses = getHousesByCity(city);

  if (houses.empty()) {
      return {};
  }

  // Apply additional filters (beds, baths, zip)
  std::vector<House> filtered;
  filtered.reserve(houses.size());

  for (const auto &h : houses) {
    if (beds != 0 && h.beds != beds) continue;
    if (baths != 0 && h.baths != baths) continue;
    if (zip_code != "" && h.zip_code != zip_code) continue;
    filtered.push_back(h);
  }

  if (filtered.empty()) {
    return {};
  }

  // Sort by price (ascending)
  std::sort(filtered.begin(), filtered.end());

  // Return up to 'count' elements
  if (filtered.size() > static_cast<size_t>(count)) {
      return std::vector<House>(filtered.begin(), filtered.begin() + count);
  }

  return filtered;
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

