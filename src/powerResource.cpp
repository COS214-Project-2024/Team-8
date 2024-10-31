#include "powerResource.h"
/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
powerResource::powerResource(){
    availablePower = 1000;
}
/**
 * @brief give power to the city sector, return true if there is enough power and decrease the availabe power by the power given to the city sector, otherwise return false
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool powerResource::giveResource(float units){
    if(units > availablePower){
        return false;
    }

    availablePower = availablePower - units;

    return true;
}
/**
 * @brief Get Power from a city sector, increase the available Power by the amount received from said City Sector
 * 
 * @param units 
 */
void powerResource::receiveResource(){
    availablePower += citySectors->replenishPower();
}
/**
 * @brief Get the available amount of power available.
 * 
 * @return float 
 */
float powerResource::getAvailableAmount(){
    return availablePower;
}
/**
 * brief Notify all city sectors that need power that there is no power left
 * 
 */
/*void powerResource::outOfResources(){
    citySectors
}*/