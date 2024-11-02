#include "constructionResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
constructionResource::constructionResource(){
    constructionMaterial = 1000;
}
/**
 * @brief give power to the city sector, return true if there is enough power and decrease the availabe power by the power given to the city sector, otherwise return false
 * 
 * @param units 
 * @return true 
 * @return false 
 */
bool constructionResource::giveResource(float units){
    if(units > constructionMaterial){
        return false;
    }

    constructionMaterial = constructionMaterial - units;

    return true;
}
/**
 * @brief Get Construction Material from a city sector, increase the available Construction by the amount received from said City Sector
 * 
 * @param units 
 */
void constructionResource::receiveResource(){
    constructionMaterial += citySectors->replenishConstResource();
}

/**
 * @brief Get the available amount of construction material available.
 * 
 * @return float 
 */
float constructionResource::getAvailableAmount(){
    return constructionMaterial;
}