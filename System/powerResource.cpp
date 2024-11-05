#include "powerResource.h"
/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
powerResource::powerResource(){
    availablePower = 1000;
}
/**
 * @brief Return true if the requested amount of power can be supplied and subtract the available power, otherwise return false if it can not be supplied.
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
 * @brief Get Power from a Power Plant, increase the available Power by the amount received from said Power Plant
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