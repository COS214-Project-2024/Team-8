#include "PublicServiceBuilding.h"
#include <string>
using namespace std;
#ifndef SCHOOL_H
#define SCHOOL_H

class School : PublicServiceBuilding {
// Building details
    string buildingName;
    string buildingType;
    Citizen* listOfCitizens;

    // Resource and maintenance requirements
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
	int waste;
	int employment;
	float educationCoverage;
    // Resource mediator and state
    ResourceMediator* resources;
    State* state;

public:
    // Pure virtual functions for building operations
	School(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int employment, float eCov);
    virtual bool cleanSewage();
    virtual bool cleanWaste();
    virtual string getBuildingType();
    virtual int getWaterCost();
    virtual int getJobsCreated();
    virtual double getMaintenanceCost();
    virtual string getName();
    virtual int getPowerReq();
    virtual int getSewageCost();
	virtual int getWasteCost();
    virtual void operation();
    virtual bool payMaintenance();
    virtual bool receivePower();
    virtual bool receiveWater();
    virtual void requestState();
	float getEducationCoverage();
	void setState();
};

#endif
