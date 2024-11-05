#include "City.h"
#ifndef CITY_CPP
#define CITY_CPP

City::City()
{
    this->buildings = NULL;
    this->Population = NULL;
    this->resources.empty();
    this->TotalIncome = 0;
    this->TotalPower = 0;
    this->TotalSewageManagment = 0;
    this->TotalWasteManagment = 0;
    this->TotalWatersupply = 0;
}

void City::runsimulation()
{
    std::cout << "Simulation is Running \n";
}

int City::CalculateTotalWaste()
{
    this->TotalSewageManagment = this->Controller.getCurrentEnergySupply();
    return this->TotalSewageManagment;
}

void City::createCitizens(int amount)
{
    if (amount == 0)
        return;

    Citizen **newCitizens = new Citizen *[amount];

    for (int i = 0; i < amount; i++)
    {
        newCitizens[i] = new Citizen;
        this->Controller.addCitizen(newCitizens[i]);
    }
}

int City::CalculateTotalWater()
{
    this->TotalWatersupply = this->Controller.getCurrentWaterSupply();
    return this->TotalWatersupply;
}

int City::CalculateTotalSewage()
{
    this->TotalSewageManagment = this->Controller.getCurrentSewageSupply();
    return this->TotalSewageManagment;
}

int City::CalculateTotalPower()
{
    this->TotalPower = this->Controller.getCurrentEnergySupply();
    return this->TotalPower;
}

void City::BuildFactory()
{
    Buildings *newBuilding = FactoryBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildWarehouse()
{
    Buildings *newBuilding = WarehouseBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildMedical()
{
    Buildings *newBuilding = MedicalCentreBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildSchool()
{
    Buildings *newBuilding = SchoolBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildPolice()
{
    Buildings *newBuilding = PoliceStationBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildOffice()
{
    Buildings *newBuilding = OfficeBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildMall()
{
    Buildings *newBuilding = MallBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildPark()
{
    Buildings *newBuilding = ParkBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildMonument()
{
    Buildings *newBuilding = MonumentBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildCulturalCenter()
{
    Buildings *newBuilding = CulturalCentreBuilder.createBuilding();
    this->Controller.addBuilding(newBuilding);
}

void City::BuildWaterUtility()
{
    Utility *newUtility = WaterBuilder.createUtility(100);
    this->Controller.addUtility(newUtility);
}

void City::BuildPowerUtility()
{
    Utility *newUtility = PowerBuilder.createUtility(100);
    this->Controller.addUtility(newUtility);
}

void City::BuildWasteUtility()
{
    Utility *newUtility = WasteBuilder.createUtility(100);
    this->Controller.addUtility(newUtility);
}

void City::BuildSewageUtility()
{
    Utility *newUtility = SewageBuilder.createUtility(100);
    this->Controller.addUtility(newUtility);
}

void City::remUtility(Utility *U)
{
    this->Controller.remUtility(U);
}

void City::remBuilding(Buildings *B)
{
    this->Controller.remBuilding(B);
}

void City::remCitizen(Citizen *C)
{
    this->Controller.remCitizen(C) ; 
}

City::~City()
{
}

#endif