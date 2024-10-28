#ifndef UTILITIESCONTROL_H
#define UTILITIESCONTROL_H

#include "CitySector.h"
#include "UtilityPowerPlant.h"
#include "WaterSupply.h"
#include "WasteManagment.h"
#include "SewageSystems.h"

class UtilitesControl
{
private:
    /* data */
    CitySector * ListOfUtilites ; 
    int amountOfUtil ; 
public:
    UtilitesControl(/* args */);
    ~UtilitesControl();

    int getTotalPower() ; 
    int getTotalSewage() ; 
    int getTotalWaste() ; 
    int getTotalWater() ; 

};

UtilitesControl::UtilitesControl(/* args */)
{
}

UtilitesControl::~UtilitesControl()
{
}

inline int UtilitesControl::getTotalPower()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<UtilityPowerPlant * >(ListOfUtilites) ) 
        {
            Res += this->ListOfUtilites->getResource() ; 
        }
    }
    return Res;
}

inline int UtilitesControl::getTotalSewage()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<SewageSystem * >(ListOfUtilites) ) 
        {
            Res += this->ListOfUtilites->getResource() ; 
        }

    }
    return Res;
}

inline int UtilitesControl::getTotalWaste()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WasteManagment * >(ListOfUtilites) ) 
        {
            Res += this->ListOfUtilites->getResource() ; 
        }

    }
    return Res;
}

inline int UtilitesControl::getTotalWater()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WaterSupply * >(ListOfUtilites) ) 
        {
            Res += this->ListOfUtilites->getResource() ; 
        }

    }
    return Res;
}

#endif
