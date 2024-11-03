#include "sewageManagementResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
sewageManagementResource::sewageManagementResource(){
    availabeSewageMan = 1000;
}
/**
 * @brief Return true if the requested units of sewage cleaning can be supplied and subtract the available resource, otherwise return false if it can not be supplied.
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
 * @brief Get sewage cleaning capabilities from sewage management, increase the available capability for sewage cleaning by the amount received from said Sewage Management
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