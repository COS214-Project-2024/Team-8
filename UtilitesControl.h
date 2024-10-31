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
    CitySector ** ListOfUtilites ; 
    int amountOfUtil ; 
public:
    UtilitesControl(/* args */);
    ~UtilitesControl();

    int getTotalPower() ; 
    int getTotalSewage() ; 
    int getTotalWaste() ; 
    int getTotalWater() ; 

    void addUtilities(CitySector * add) ;
    void removeUtilities(CitySector * rem) ;
    int getAmountOfUtilities() ; 

};

UtilitesControl::UtilitesControl(/* args */)
{
    this->amountOfUtil = 0 ;
    this->ListOfUtilites = NULL ; 
}

UtilitesControl::~UtilitesControl()
{
}

inline int UtilitesControl::getTotalPower()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<UtilityPowerPlant * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getResource() ; 
        }
    }
    return Res;
}

inline int UtilitesControl::getTotalSewage()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<SewageSystem * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getResource() ; 
        }

    }
    return Res;
}

inline int UtilitesControl::getTotalWaste()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WasteManagment * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getResource() ; 
        }

    }
    return Res;
}

inline int UtilitesControl::getTotalWater()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WaterSupply * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getResource() ; 
        }

    }
    return Res;
}

void UtilitesControl::addUtilities(CitySector * add)
{
    if ( this->amountOfUtil == 0)
    {
        this->ListOfUtilites = new CitySector * [1] ; 
        this->ListOfUtilites[0] = add ; 
        this->amountOfUtil++ ; 

    }
        else
    {
        CitySector** newListOfUtilites = new CitySector*[this->amountOfUtil + 1];
        
        for (int i = 0; i < this->amountOfUtil; i++)
        {
            newListOfUtilites[i] = this->ListOfUtilites[i];
        }

        newListOfUtilites[this->amountOfUtil] = add;

        delete[] this->ListOfUtilites;

        this->ListOfUtilites = newListOfUtilites;
        this->amountOfUtil++;
    }
}

void UtilitesControl::removeUtilities(CitySector *rem)
{
    if (this->amountOfUtil == 0) 
    {
        return; 
    }

    int indexToRemove = -1;
    for (int i = 0; i < this->amountOfUtil; i++)
    {
        if (this->ListOfUtilites[i] == rem)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) 
    {
        return; 
    }

    CitySector **newListOfUtilites = new CitySector*[this->amountOfUtil - 1];

    for (int i = 0, j = 0; i < this->amountOfUtil; i++)
    {
        if (i != indexToRemove) 
        {
            newListOfUtilites[j++] = this->ListOfUtilites[i];
        }
    }

    delete[] this->ListOfUtilites;

    this->ListOfUtilites = newListOfUtilites;
    this->amountOfUtil--;

}

inline int UtilitesControl::getAmountOfUtilities()
{
    return this->amountOfUtil ;
}

#endif
