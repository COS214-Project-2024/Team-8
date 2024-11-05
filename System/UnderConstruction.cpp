#include <iostream>
#include "UnderConstruction.h"
#include "Operational.h"
#include "Utility.h"

UnderConstruction::UnderConstruction()
{
    this->stateName = "Under Construction";
    this->building = nullptr; // Initialize to nullptr or set it through another method
}

void UnderConstruction::handle() {
    std::cout << "This building is under construction!" << std::endl;
}

void UnderConstruction::changeState() {
    if (this->building && this->building->resources != nullptr) // Ensure building is initialized
    {
        if (building->getPower() && building->getWater()) // Changed to getWater
        {
            State* newState = new Operational();
            building->setState(newState);
            std::cout << "The building is now Operational, resources have been replenished!" << std::endl;
        }
    }
    else
    {
        // If the resources are unavailable, the building will remain under construction.
        std::cout << "No resources available. Please replenish resources to make this building operational." << std::endl;
    }
}

std::string UnderConstruction::getStateName()
{
    return this->stateName;
}
