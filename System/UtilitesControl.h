#ifndef UTILITIESCONTROL_H
#define UTILITIESCONTROL_H

#include "CitySector.h"
#include "Utility.h"
#include "UtilityPowerPlant.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "SewageSystems.h"

class UtilitesControl
{
private:
    Utility ** ListOfUtilites ; 
    int amountOfUtil ; 
public:
    UtilitesControl(/* args */);
    ~UtilitesControl();

    int getTotalPower() ; 
    int getTotalSewage() ; 
    int getTotalWaste() ; 
    int getTotalWater() ; 

    void addUtilities(Utility * add) ;
    void removeUtilities(Utility * rem) ;
    int getAmountOfUtilities() ; 

};

#endif
