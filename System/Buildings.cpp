#include "Buildings.h"
#include "State.h"      // Add full State class definition
#include "Citizen.h"    // Add full Citizen class definition
#include "Utility.h"

Buildings::Buildings() : 
    profit(0),
    sales(0),
    balance(0),
    state(nullptr),
    powerReq(0),
    waterReq(0),
    sewageCost(0),
    maintenanceCost(0),
    buildingName(""),
    buildingType(""),
    listOfCitizens(nullptr),
    resources(nullptr)
{
}

Buildings::~Buildings() {
   /* if (listOfCitizens != nullptr) {
        delete listOfCitizens;
        listOfCitizens = nullptr;
    }
    if (state != nullptr) {
        delete state;
        state = nullptr;
    }*/
}

int Buildings::getBirthRate() {
    return 0;
}

void Buildings::setResources(Utility* res) {
    this->resources = res;
}