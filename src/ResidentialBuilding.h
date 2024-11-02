#include "Buildings.h"
#include <string>
using namespace std;

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

class ResidentialBuilding : Buildings {

protected:
    // Basic building details
    string buildingName;
    string buildingType;
    Citizen* listOfCitizens;

    // Maintenance and resource requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
    int capacity;

    // Mediator and state
    ResourceMediator* resources;
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

};

#endif

