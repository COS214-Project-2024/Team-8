#include "ResidentialBuilding.h"
#include <string>
using namespace std;

#ifndef HOUSE_H
#define HOUSE_H

class House : ResidentialBuilding {

protected:
    // Building details
    string buildingName;
    string buildingType;
    int capacity;
    Citizen* listOfCitizens;

    // Resource and maintenance requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
	int waste;

    // Mediator and state
    ResourceMediator* resources;
    State* state;

public:
    // Pure virtual functions for building operations
	House(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int capacity);
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
	Citizen* getListOfResidents();
	int getCapacity();
	int getWasteCost();

};

#endif
