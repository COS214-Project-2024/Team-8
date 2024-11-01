#ifndef BUILDINGCONTROLLER_H
#define BUILDINGCONTROLLER_H

#include "Citizen.h"
#include "Buildings/Buildings.h"
#include "Buildings/ResidentialBuilding.h"
#include "Buildings/CommercialBuilding.h"

#include <iostream>

class BuildingController
{
private:

    Buildings ** ListOfBuildings ; 
    int amountOfBuildings ; 
public:
    BuildingController(/* args */);
    ~BuildingController();

    
    void addBuilding(Buildings * add) ;
    void removeBuilding(Buildings * rem) ;
    int getAmountOfBuildings() ; 

    int getTotalPowerReq() ; 
    int getTotalSewageReq() ; 
    int getTotalWasteReq() ; 
    int getTotalWaterReq() ; 
    int getMaintenanceCost() ; 

    Citizen** getListOfCitizens() ; 
    int getCommercialIncome() ; 


};

#endif