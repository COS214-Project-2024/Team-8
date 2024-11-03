#include "Resource.h"
#include "ResourceMediator.h"
/**
 * @brief Set the mediator attribute of the Resource Mediator
 * 
 * @param mediator 
 */
void Resource::setResourceMediator(ResourceMediator* mediator){
    this->citySectors = mediator;
}