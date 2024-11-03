#include "constructionResource.h"

/**
 * @brief Construct a new power Resource::power Resource object
 * 
 */
constructionResource::constructionResource(){
    constructionMaterial = 1000;
}
/**
 * @brief Return true if the requested amount of construction material can be supplied and subtract the available material, otherwise return false if it can not be supplied.
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
 * @brief Get Construction Material from the City, increase the available Construction by the amount received.
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