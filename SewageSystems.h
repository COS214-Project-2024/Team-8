#ifndef SEWAGESUPPLY_H
#define SEWAGESUPPLY_H

#include "CitySector.h"

class SewageSystem : public CitySector
{
private:
    /* data */
    int SewageRemovalAmount ; 
public:
    SewageSystem(/* args */);
    ~SewageSystem();
    int getResources() ; 
};

SewageSystem::SewageSystem(/* args */)
{
}

SewageSystem::~SewageSystem()
{
}

inline int SewageSystem::getResources()
{
    return SewageRemovalAmount;
}

#endif
