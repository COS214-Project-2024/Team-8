#include "wasteManagementResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
wasteManagementResource::wasteManagementResource(){
    availableWasteManagment = 1000;
}
/**
 * @brief Return true if the requested units of waste cleaning can be supplied and subtract the available resource, otherwise return false if it can not be supplied.
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool wasteManagementResource::giveResource(float units){
    if(units > availableWasteManagment){
        return false;
    }

    availableWasteManagment = availableWasteManagment - units;

    return true;
}
/**
 * @brief Get waste cleaning capabilities from waste Management, increase the available capabilities for waste cleaning by the amount received from said waste Management
 * 
 * @param units 
 */
void wasteManagementResource::receiveResource(){
    availableWasteManagment += citySectors->gainWasteCleaning();
}
/**
 * @brief Get the available amount of waste cleaning resources available.
 * 
 * @return float 
 */
float wasteManagementResource::getAvailableAmount(){
    return availableWasteManagment;
}