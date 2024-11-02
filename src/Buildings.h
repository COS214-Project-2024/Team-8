#include <string>
using namespace std;
#ifndef BUILDINGS_H
#define BUILDINGS_H

class State;
class ResourceMediator;
class Citizen;

class Buildings {
public:
    State* state;

protected:
    ResourceMediator* resources;
    int powerReq;
    int waterReq;
    int sewageCost;
    double maintenanceCost;
    string buildingName;
    string buildingType;
    Citizen* listOfCitizens;

public:
    // Pure virtual functions to be implemented by derived classes
    virtual void requestState() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual int getPowerReq() = 0;
    virtual int getSewageCost() = 0;
    virtual int getWaterCost() = 0;
    virtual string getName() = 0;
    virtual string getBuildingType() = 0;
    virtual int getJobsCreated() = 0;

    // Resource management functions
    virtual bool receivePower() = 0;
    virtual bool receiveWater() = 0;
    virtual bool payMaintenance() = 0;
    virtual bool cleanWaste() = 0;
    virtual bool cleanSewage() = 0;

    // General operation function
    virtual void operation() = 0;

};

#endif
#endif
