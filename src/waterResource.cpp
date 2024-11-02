#include "waterResource.h"

/**
 * @brief Construct a new power Resource:: Resource object
 * 
 */
waterResource::waterResource(){
    availableWater = 1000;
}
/**
 * @brief Return true if the requested amount of water can be supplied, otherwise return false.
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool waterResource::giveResource(float units){
    if(units > availableWater){
        return false;
    }

    availableWater = availableWater - units;

    return true;
}
/**
 * @brief Get water from a city sector, increase the available water by the water received from said City Sector
 * 
 * @param units 
 */
void waterResource::receiveResource(){
    availableWater += citySectors->replenishWater();
}
/**
 * @brief Get the available amount of water
 * 
 * @return float 
 */
float waterResource::getAvailableAmount(){
    return availableWater;
}