#include "Resource.h"
#include "ResourceMediator.h"
void Resource::setResourceMediator(ResourceMediator* mediator){
    this->citySectors = mediator;
}