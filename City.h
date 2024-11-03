#ifndef CITY_H
#define CITY_H

#include <vector>
#include <iostream>

#include "PopulationControl.h"
#include "Buildings.h"
#include "ResourceMediator.h"
#include "Resources.h"
#include "Utility.h"
#include "CitySector.h"
#include "CityController.h"

class City
{
private:

    Government DesignWits ; 

    CityController Controller ; 

    int AmountOfBuildings ; 
    int AmountOfUtilities ;

    CitySector * buildings; // 
    std::vector<Resources *> resources;
    ResourceMediator *resourceMediator;

    int TotalWasteManagment;
    int TotalSewageManagment;
    int TotalWatersupply;
    double TotalIncome;
    int TotalPower ; 

    int TotalWasteReq;
    int TotalSewageReq;
    int TotalReq;
    int TotalPowerReq ; 

    PopulationControl *Population;
    int AmountOfPop ; 

    Utility *ListOfUtilityBuildings;

public:
    City(/* args */);
    void runsimulation();

    int CalculateTotalWaste()  ;
    int CalculateTotalWater()  ;
    int CalculateTotalSewage() ;
    int CalculateTotalPower()  ; 

    ~City();
};

#endif