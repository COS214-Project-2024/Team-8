#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "CitySector.h"

class WaterSupply : public CitySector
{
private:
    /* data */
    int WaterSupplyLimit ; 
public:
    WaterSupply(/* args */);
    ~WaterSupply();
    int getResources() ; 
};

WaterSupply::WaterSupply(/* args */)
{
}

WaterSupply::~WaterSupply()
{
}

inline int WaterSupply::getResources()
{
    return WaterSupplyLimit;
}

#endif
