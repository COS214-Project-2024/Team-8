#include "sewageManagementResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
sewageManagementResource::sewageManagementResource(){
    availabeSewageMan = 1000;
}
/**
 * @brief give power to the city sector, return true if there is enough power and decrease the availabe power by the power given to the city sector, otherwise return false
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool sewageManagementResource::giveResource(float units){
    if(units > availabeSewageMan){
        return false;
    }

    availabeSewageMan = availabeSewageMan - units;

    return true;
}
/**
 * @brief Get sewage cleaning capabilities from a city sector, increase the available capability for sewage cleaning by the amount received from said City Sector
 * 
 * @param units 
 */
void sewageManagementResource::receiveResource(){
    availabeSewageMan += citySectors->gainSewageCleaning();
}
/**
 * @brief Get the available amount of sewage cleaning capabilities available
 * 
 * @return float 
 */
float sewageManagementResource::getAvailableAmount(){
    return availabeSewageMan;
}