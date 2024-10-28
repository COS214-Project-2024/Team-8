#ifndef WASTEMANAGMENT_H
#define WASTEMANAGMENT_H

#include "CitySector.h"

class WasteManagment : public CitySector
{
private:
    /* data */
    int WasteRemovalAmount ; 
public:
    WasteManagment(/* args */);
    ~WasteManagment();
    int getResources() ; 
};

WasteManagment::WasteManagment(/* args */)
{
}

WasteManagment::~WasteManagment()
{
}

inline int WasteManagment::getResources()
{
    return WasteRemovalAmount;
}

#endif
