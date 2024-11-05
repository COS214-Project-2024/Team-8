#include "revenueResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
revenueResource::revenueResource(){
    availableRevenue = 1000;
}
/**
 * @brief Return true if the requested units of Revenue can be given and subtract the available Revenue, otherwise return false if it can not be given.
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool revenueResource::giveResource(float units){
    if(units > availableRevenue){
        return false;
    }

    availableRevenue = availableRevenue - units;

    return true;
}
/**
 * @brief Get Revenue from the city, increase the available revenue by the amount received
 * 
 * @param units 
 */
void revenueResource::receiveResource(){
    availableRevenue += citySectors->replenishRevenue();
}
/**
 * @brief Get the available amount of revenue available
 * 
 * @return float 
 */
float revenueResource::getAvailableAmount(){
    return availableRevenue;
}