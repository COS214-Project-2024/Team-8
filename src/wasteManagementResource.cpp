#include "wasteManagementResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
wasteManagementResource::wasteManagementResource(){
    availableWasteManagment = 1000;
}
/**
 * @brief give power to the city sector, return true if there is enough power and decrease the availabe power by the power given to the city sector, otherwise return false
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
 * @brief Get waste cleaning capabilities from a city sector, increase the available capabilities for waste cleaning by the amount received from said City Sector
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