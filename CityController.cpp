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

int CityController::getAmountOfUtilities()
{
    return this->ManagmentOfUtilities.getAmountOfUtilities() ; 
}

double CityController::getTotalIncome()
{
    return this->getBuildingCommercialIncome() + this->TaxableIncome() ;
}

int CityController::getBuildingWaterCost()
{
    return this->ManagmentOfBuildings.getTotalWaterReq();
}

int CityController::getBuildingPowerCost()
{
    return this->ManagmentOfBuildings.getTotalPowerReq();
}

int CityController::getBuildingWasteCost()
{
    return this->ManagmentOfBuildings.getTotalWasteReq();
}

int CityController::getBuildingSewageCost()
{
    return this->ManagmentOfBuildings.getTotalSewageReq();
}

Citizen** CityController::getBuildingCitizenInRes()
{
    return this->ManagmentOfBuildings.getListOfCitizens() ;
}

int CityController::getBuildingCommercialIncome()
{
    return this->ManagmentOfBuildings.getCommercialIncome();
}

int CityController::AmountOfCitizens()
{
    return ManagmentOfCitizens.getAmountOfCitizens() ; 
}

int CityController::EmployedCitizens()
{
    return ManagmentOfCitizens.getEmployedCitizensAmount() ; 
}

int CityController::PropertyOwners()
{
    return ManagmentOfCitizens.getamountPropertyOwnersAmount() ; 
}

double CityController::AvgSatisfaction()
{
    return ManagmentOfCitizens.getAvgSatisfaction() ; 
}

float CityController::TaxableIncome()
{
    return ManagmentOfCitizens.GetTaxableIncome() ; 
}

Citizen **CityController::getListOfCitizens()
{
    return ManagmentOfCitizens.getListOfCitizens() ;
}

#endif
