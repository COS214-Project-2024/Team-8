#ifndef RESOURCEMEDIATOR_H
#define RESOURCEMEDIATOR_H

#include <map>
#include <iostream>
#include <vector>
#include <memory>


#include "Buildings.h"

#include "waterSupply.h"
#include "Resource.h"

class Resource;
class Buildings;

class ResourceMediator {
private:
    std::map<std::string, Resource*>* resources;
    std::vector<utility*>* utilities;

public:
    ResourceMediator();
    bool usePower(float units, Buildings* sender);
    float replenishPower();
    bool useRevenue(float units, Buildings* sender);
    float replenishRevenue();
    bool useWater(float units, Buildings* sender);
    float replenishWater();
    bool cleanWaste(float units, Buildings* sender);
    float gainWasteCleaning();
    bool cleanSewage(float units, Buildings* sender);
    float gainSewageCleaning();
    bool useConstResource(float units, Buildings* sender);
    float replenishConstResource();
    void setResources(std::map<std::string, Resource*>* resources);
    void setUtilities(std::vector<utility*>* utilities);
};

#endif // RESOURCEMEDIATOR_H
