#include "ResidentialBuilding.h"
#include <string>

using namespace std;

#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

class TownHouse : ResidentialBuilding {

protected:
    // Building details
    string buildingName;
    string buildingType;
    int capacity;
    Citizen* listOfCitizens;

    // Maintenance and resource requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
    int waste;

    // Resource mediator and state
    ResourceMediator* resources;
    State* state;

public:
    // Virtual functions for building operations
	TownHouse(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity);
    virtual bool cleanSewage();
    virtual bool cleanWaste();
    virtual string getBuildingType();
    virtual int getJobsCreated();
    virtual double getMaintenanceCost();
    virtual string getName();
    virtual int getPowerReq();
    virtual int getSewageCost();
    virtual int getWaterReq();
    virtual void operation();
    virtual bool payMaintenance();
    virtual bool receivePower();
    virtual bool receiveWater();
    virtual void requestState();
    void setState();
    int getWasteCost();
    int getCapacity();
    Citizen* getListOfResidents();


};

#endif
