#include "revenueResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
revenueResource::revenueResource(){
    availableRevenue = 1000;
}
/**
 * @brief give power to the city sector, return true if there is enough power and decrease the availabe power by the power given to the city sector, otherwise return false
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
 * @brief Get Revenue from a city sector, increase the available revenue by the amount received from said City Sector
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