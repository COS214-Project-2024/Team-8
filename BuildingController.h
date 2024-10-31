#ifndef BUILDINGCONTROLLER_H
#define BUILDINGCONTROLLER_H

#include "CitySector.h"
#include "Citizen.h"
#include <iostream>

class BuildingController
{
private:

    CitySector ** ListOfBuildings ; 
    int amountOfBuildings ; 
public:
    BuildingController(/* args */);
    ~BuildingController();

    void addBuilding(CitySector * add) ;
    void removeBuilding(CitySector * rem) ;
    int getAmountOfBuildings() ; 

    int getTotalPowerReq() ; 
    int getTotalSewageReq() ; 
    int getTotalWasteReq() ; 
    int getTotalWaterReq() ; 
    int getMaintenanceCost() ; 

    Citizen** getListOfCitizens() ; 
    int getCommercialIncome() ; 


};

BuildingController::BuildingController(/* args */)
{
    this->amountOfBuildings = 0 ;
    this->ListOfBuildings = NULL ; 
}

BuildingController::~BuildingController()
{
}

Citizen** BuildingController::getListOfCitizens()
{
    int Res = 0 ; 
    int amountOfRes = 0 ; 

    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        if ( dynamic_cast<ResidentialBuilding * >(ListOfBuildings[i]) ) 
        {
            amountOfRes++; 
        }
    }

    Citizen** ListOfCitizens = new Citizen* [amountOfRes] ; 

    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        if ( dynamic_cast<ResidentialBuilding * >(ListOfBuildings[i]) ) 
        {
            ListOfCitizens[Res] = this->ListOfBuildings[i].getListOfResidents() ; 
            Res++ ;
        }
    }


    return ListOfCitizens ;

}

void BuildingController::addBuilding(CitySector *add)
{
    if ( this->amountOfBuildings == 0)
    {
        this->ListOfBuildings = new CitySector * [1] ; 
        this->ListOfBuildings[0] = add ; 
        this->amountOfBuildings++ ; 

    }
        else
    {
        CitySector** newListOfBuildings = new CitySector*[this->amountOfBuildings + 1];
        
        for (int i = 0; i < this->amountOfBuildings; i++)
        {
            newListOfBuildings[i] = this->ListOfBuildings[i];
        }

        newListOfBuildings[this->amountOfBuildings] = add;

        delete[] this->ListOfBuildings;

        this->ListOfBuildings = newListOfBuildings;
        this->amountOfBuildings++;
    }
}

void BuildingController::removeBuilding(CitySector *rem)
{
    if (this->amountOfBuildings == 0) 
    {
        return; 
    }

    int indexToRemove = -1;
    for (int i = 0; i < this->amountOfBuildings; i++)
    {
        if (this->ListOfBuildings[i] == rem)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) 
    {
        return; 
    }

    CitySector **newListOfBuildings = new CitySector*[this->amountOfBuildings - 1];

    for (int i = 0, j = 0; i < this->amountOfBuildings; i++)
    {
        if (i != indexToRemove) 
        {
            newListOfBuildings[j++] = this->ListOfBuildings[i];
        }
    }

    delete[] this->ListOfBuildings;

    this->ListOfBuildings = newListOfBuildings;
    this->amountOfBuildings--;
}

int BuildingController::getAmountOfBuildings()
{
    this->amountOfBuildings ; 
}

inline int BuildingController::getTotalPowerReq()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getPowerReq() ; 
    }
    return Res;
}

inline int BuildingController::getTotalSewageReq()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getSewageCost() ; 
    }
    return Res;
}

inline int BuildingController::getTotalWasteReq()
{
       int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getWasteCost() ; 
    }
    return Res;
}

inline int BuildingController::getTotalWaterReq()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getWaterReq() ; 
    }
    return Res;
}

inline int BuildingController::getMaintenanceCost()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getMaintenanceCost() ; 
    }
    return Res;
}

int BuildingController::getCommercialIncome()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        if ( dynamic_cast<CommercialBuilding * >(ListOfBuildings[i]) ) 
        {
            Res += this->ListOfBuildings[i]->getIncome() ; 
        }
    }
    return Res;
}

#endif