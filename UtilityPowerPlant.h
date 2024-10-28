#ifndef UTILITYPOWERPLANT_H
#define UTILITYPOWERPLANT_H

#include "CitySector.h"

class UtilityPowerPlant : public CitySector
{
private:
    /* data */
    int PowerSupply ; 
public:
    UtilityPowerPlant(/* args */);
    ~UtilityPowerPlant();
    int getResources() ; 
};

UtilityPowerPlant::UtilityPowerPlant(/* args */)
{
}

UtilityPowerPlant::~UtilityPowerPlant()
{
}

inline int UtilityPowerPlant::getResources()
{
    return PowerSupply;
}

#endif
