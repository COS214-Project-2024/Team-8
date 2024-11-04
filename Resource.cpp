#include "Resource.h"
#include "Utility.h"
/**
 * @brief Set the mediator attribute of the Resource Mediator
 * 
 * @param mediator 
 */
void Resource::setUtility(Utility* mediator){
    this->citySectors = mediator;
}