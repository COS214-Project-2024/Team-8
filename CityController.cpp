#ifndef CITYCONTROLLER_CPP
#define CITYCONTROLLER_CPP

#include "CityController.h"

CityController::CityController()
{
}

CityController::~CityController()
{
}

void CityController::Update()
{
}

Policy *CityController::evaluatePolicies()
{
    return nullptr;
}

Citizen *CityController::handleCitizenNeedsAndSatisfaction()
{
    return nullptr;
}

PopulationControl *CityController::evaluatePopulationControl()
{
    return nullptr;
}

void CityController::addDecorations()
{
}

void CityController::ProvideUtilities()
{
}

Resources *CityController::buildInfrastructure()
{
    return nullptr;
}

int CityController::getTransportCapacity()
{
    return 0;
}

int CityController::getCurrentEnergySupply()
{
    this->ManagmentOfUtilities.getTotalPower() ; 
}

int CityController::getCurrentWasteSupply()
{
    this->ManagmentOfUtilities.getTotalWaste() ; 
}

int CityController::getCurrentWaterSupply()
{
    this->ManagmentOfUtilities.getTotalWater() ; 
}

int CityController::getCurrentSewageSupply()
{
    this->ManagmentOfUtilities.getTotalSewage() ; 
}

#endif
