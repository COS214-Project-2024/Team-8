#include "City.h"
#ifndef CITY_CPP
#define CITY_CPP

City::City()
{
    this->buildings = NULL ; 
    this->Population = NULL ;
    this->resources.empty() ;
    this->TotalIncome = 0 ;
    this->TotalPower = 0 ;
    this->TotalSewageManagment = 0 ;
    this->TotalWasteManagment = 0 ;
    this->TotalWatersupply = 0 ;  
}

void City::runsimulation()
{
    std::cout << "Simulation is Running \n" ; 
}

int City::CalculateTotalWaste()
{
    this->TotalSewageManagment = this->Controller.getCurrentEnergySupply() ; 
}

int City::CalculateTotalWater()
{
    this->TotalWatersupply = this->Controller.getCurrentWaterSupply() ; 
}

int City::CalculateTotalSewage()
{
    this->TotalSewageManagment = this->Controller.getCurrentSewageSupply() ;
}

int City::CalculateTotalPower()
{
    this->TotalPower = this->Controller.getCurrentEnergySupply() ; 
}

City::~City()
{
}

#endif