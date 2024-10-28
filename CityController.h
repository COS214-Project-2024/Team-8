#ifndef CITYCONTROLLER_H
#define CITYCONTROLLER_H

#include "Buildings.h"
#include "PopulationControl.h"
#include "Resources.h"
#include "Policy.h"
#include "Citizen.h"
#include "UtilitesControl.h"


class CityController
{
private:
    /* data */
    UtilitesControl ManagmentOfUtilities ; 
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
    Buildings* createBuilding ; // Was Buildier , changed to Buildings  

    int getTransportCapacity() ; // How do I cycle through the Transports , where is it stored ?
    int getCurrentEnergySupply() ; 
    int getCurrentWasteSupply() ; 
    int getCurrentWaterSupply() ; 
    int getCurrentSewageSupply() ; 

    double getTotalIncome() ; // Through Citizen Interface I presume ?

};

#endif