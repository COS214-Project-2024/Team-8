#include <string>
#include "Buildings.h"
using namespace std;

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

class Citizen;
class ResourceMediator;
class State;


class CommercialBuilding : Buildings {

protected:
    // Basic building details
    string buildingName;
    string buildingType;
    Citizen* listOfCitizens;

    // Resource and cost requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
    ResourceMediator* resources;

    // Business metrics
    float sales;
    float profit;
    int employment;

    // Current building state
    State* state;

public:
    // Pure virtual functions for building operations
    virtual bool cleanSewage() = 0;
    virtual bool cleanWaste() = 0;
    virtual string getBuildingType() = 0;
    virtual int getJobsCreated() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual string getName() = 0;
    virtual int getPowerReq() = 0;
    virtual int getSewageCost() = 0;
    virtual int getWaterCost() = 0;
    virtual void operation() = 0;
    virtual bool payMaintenance() = 0;
    virtual bool receivePower() = 0;
    virtual bool receiveWater() = 0;
    virtual void requestState() = 0;

    // Additional functions
    float getSales();
    void operation2();
    float getProfit();

};

#endif
