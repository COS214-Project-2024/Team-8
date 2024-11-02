#include "PublicServiceBuilding.h"
#include <string> 
using namespace std;
#ifndef MEDICALCENTER_H
#define MEDICALCENTER_H

class MedicalCenter : PublicServiceBuilding {

protected:
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
	int healthCoverage;
    // Resource mediator and state
    ResourceMediator* resources;
    State* state;

public:
    // Pure virtual functions for building operations
	MedicalCenter(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment, int hCov);
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
	int getHealthCoverage();
	void setState();
};

#endif
