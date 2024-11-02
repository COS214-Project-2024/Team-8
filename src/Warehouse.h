#include "IndustrialBuilding.h"
#include <string>

using namespace std;
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class Warehouse : IndustrialBuilding {

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
	int waste;
    ResourceMediator* resources;

    // Business metrics
    float sales;
    float profit;
    int employment;

    // Current building state
    State* state;

public:
    // Pure virtual functions for building operations
	Warehouse(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment);
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
	int getWasteCost();
	void setState();

    // Additional functions
    float getSales();
    void operation2();
    float getProfit();
};

#endif
