#ifndef BUILDINGCONTROLLER_H
#define BUILDINGCONTROLLER_H

#include "Citizen.h"
#include "Buildings.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Utility.h"

#include <iostream>

class BuildingController
{
private:

    Buildings ** ListOfBuildings ; 
    int amountOfBuildings ; 
//    Utility* Utility;
public:
    BuildingController(/* args */);
    ~BuildingController();
 /*   BuildingController(Utility* mediator) 
       : Utility(mediator) {
        ListOfBuildings = new Buildings*[100];
        amountOfBuildings = 0;
    
}*/

    
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