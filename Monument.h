#include "LandmarkBuilding.h"
#include <string>
using namespace std;

#ifndef MONUMENT_H
#define MONUMENT_H

class Monument : LandmarkBuilding {

// Basic building details
    string buildingName;
    string buildingType;
    Citizen* listOfCitizens;

    // Resource and cost requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;

    // Mediator and state objects
    ResourceMediator* resources;
    State* state;

public:
    // Pure virtual functions for building operations
    virtual bool cleanSewage();
    virtual bool cleanWaste();
    virtual string getBuildingType();
    virtual int getJobsCreated();
    virtual double getMaintenanceCost();
    virtual string getName();
    virtual int getPowerReq();
    virtual int getSewageCost();
    virtual int getWaterCost();
    virtual void operation();
    virtual bool payMaintenance();
    virtual bool receivePower();
    virtual bool receiveWater();
    virtual void requestState();

};

#endif
