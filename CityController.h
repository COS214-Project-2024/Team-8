#ifndef CITYCONTROLLER_H
#define CITYCONTROLLER_H

#include "Buildings.h"
#include "PopulationControl.h"
#include "Resources.h"
#include "Policy.h"
#include "Citizen.h"
#include "UtilitesControl.h"
#include "BuildingController.h"
#include "CitizenController.h"


class CityController
{
private:
    /* data */
    UtilitesControl ManagmentOfUtilities ; 
    BuildingController ManagmentOfBuildings ;
    CitizenController ManagmentOfCitizens ; 

public:

    CityController() ;
    ~CityController() ; 

    void Update() ;
    Policy * evaluatePolicies() ; 
    Citizen * handleCitizenNeedsAndSatisfaction() ;
    PopulationControl * evaluatePopulationControl() ;
    void addDecorations() ; // What Decorations and where ? City Sectors ? 
    void ProvideUtilities() ;
    Resources * buildInfrastructure() ; 
    Buildings* createBuilding ; // Was Builder , changed to Buildings  

    int getCurrentEnergySupply() ; 
    int getCurrentWasteSupply() ; 
    int getCurrentWaterSupply() ; 
    int getCurrentSewageSupply() ; 
    int getAmountOfUtilities() ; 

    double getTotalIncome() ; // Through Citizen Interface I presume ? Just gonna add TaxableIncome with CommercialIncome for now

    int getBuildingWaterCost() ; 
    int getBuildingPowerCost() ; 
    int getBuildingWasteCost() ; 
    int getBuildingSewageCost() ; 
    Citizen** getBuildingCitizenInRes() ; 
    int getBuildingCommercialIncome() ; 

    int AmountOfCitizens() ; 
    int EmployedCitizens() ; 
    int PropertyOwners() ;

    double AvgSatisfaction() ;
    float TaxableIncome() ; 
    Citizen** getListOfCitizens() ; 

};

#endif