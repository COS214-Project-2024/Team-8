#ifndef BUILDINGCONTROLLER_CPP
#define BUILDINGCONTROLLER_CPP

#include "BuildingController.h"

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
        if ( dynamic_cast<ResidentialBuilding  *>(ListOfBuildings[i]) ) 
        {
            ListOfCitizens[Res] = this->ListOfBuildings[i]->getlistOfResidence() ; // Residential Buildings doesnt have a getListOfResidents function , also no variable for the Residents
            Res++ ;
        }
    }


    return ListOfCitizens ;

}

void BuildingController::addBuilding(Buildings *add)
{
    if ( this->amountOfBuildings == 0)
    {
        this->ListOfBuildings = new Buildings * [1] ; 
        this->ListOfBuildings[0] = add ; 
        this->amountOfBuildings++ ; 

    }
        else
    {
        Buildings** newListOfBuildings = new Buildings*[this->amountOfBuildings + 1];
        
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

void BuildingController::removeBuilding(Buildings *rem)
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

    Buildings **newListOfBuildings = new Buildings*[this->amountOfBuildings - 1];

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

int BuildingController::getTotalPowerReq()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getPowerReq() ; 
    }
    return Res;
}

int BuildingController::getTotalSewageReq()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getSewageCost() ; 
    }
    return Res;
}

int BuildingController::getTotalWasteReq()
{
       int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getWaterReq() ; 
    }
    return Res;
}

int BuildingController::getTotalWaterReq()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < this->amountOfBuildings ; i++)
    {
        Res += this->ListOfBuildings[i]->getWaterReq() ; 
    }
    return Res;
}

int BuildingController::getMaintenanceCost()
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
             Res += dynamic_cast<CommercialBuilding * >(ListOfBuildings[i])->getProfit() ; // Commercial Buildings Doesnt have an Income 
        }
    }
    return Res;
}

#endif