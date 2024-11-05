#ifndef UTILITIESCONTROL_CPP
#define UTILITIESCONTROL_CPP

#include "UtilitesControl.h"

UtilitesControl::UtilitesControl(/* args */)
{
    this->amountOfUtil = 0 ;
    this->ListOfUtilites = NULL ; 
}

UtilitesControl::~UtilitesControl()
{
}

int UtilitesControl::getTotalPower()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<UtilityPowerPlant * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getOutput() ; 
        }
    }
    return Res;
}

int UtilitesControl::getTotalSewage()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<SewageSystems * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getOutput() ; 
        }

    }
    return Res;
}

int UtilitesControl::getTotalWaste()
{
    int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WasteManagement * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getOutput() ; 
        }

    }
    return Res;
}

int UtilitesControl::getTotalWater()
{
        int Res = 0 ; 
    for ( int i = 0 ; i < amountOfUtil ; i++)
    {
        if ( dynamic_cast<WaterSupply * >(ListOfUtilites[i]) ) 
        {
            Res += this->ListOfUtilites[i]->getOutput() ; 
        }

    }
    return Res;
}

void UtilitesControl::addUtilities(Utility * add)
{
    if ( this->amountOfUtil == 0)
    {
        this->ListOfUtilites = new Utility * [1] ; 
        this->ListOfUtilites[0] = add ; 
        this->amountOfUtil++ ; 

    }
        else
    {
        Utility** newListOfUtilites = new Utility*[this->amountOfUtil + 1];
        
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

void UtilitesControl::removeUtilities(Utility *rem)
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

    Utility **newListOfUtilites = new Utility*[this->amountOfUtil - 1];

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

int UtilitesControl::getAmountOfUtilities()
{
    return this->amountOfUtil ;
}


#endif