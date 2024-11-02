#include "CommercialBuilding.h"
#include <string> 
using namespace std;

#ifndef MALL_H
#define MALL_H

class Mall : CommercialBuilding {

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
	int income;
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
	Mall(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);
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
	void setState();
	int getIncome();
	int getWasteCost();

    // Additional functions
    float getSales();
    void operation2();
    float getProfit();
};

#endif
