#ifndef RESOURCEMEDIATOR_H
#define RESOURCEMEDIATOR_H

#include <map>
#include <iostream>
#include <vector>
#include <memory>


#include "Building.h"

#include "waterSupply.h"
#include "Resource.h"

class Resource;
class Building;

class ResourceMediator {
private:
    std::map<std::string, Resource*>* resources;
    std::vector<utility*>* utilities;

public:
    ResourceMediator();
    bool usePower(float units, Building* sender);
    float replenishPower();
    bool useRevenue(float units, Building* sender);
    float replenishRevenue();
    bool useWater(float units, Building* sender);
    float replenishWater();
    bool cleanWaste(float units, Building* sender);
    float gainWasteCleaning();
    bool cleanSewage(float units, Building* sender);
    float gainSewageCleaning();
    bool useConstResource(float units, Building* sender);
    float replenishConstResource();
    void setResources(std::map<std::string, Resource*>* resources);
    void setUtilities(std::vector<utility*>* utilities);
};

#endif // RESOURCEMEDIATOR_H
