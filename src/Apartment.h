#include <string>
using namespace std;

#ifndef APARTMENT_H
#define APARTMENT_H

class Apartment : ResidentialBuilding {

// Attributes
    string buildingName;
    string buildingType;
    int capacity;
    Citizen* listOfCitizens;         // Pointer to a list of citizens
    double maintenanceCost;
    int powerReq;
    int waterReq;
    int sewageCost;
    
    ResourceMediator* resources;     // Mediator for managing resources
    State* state;                    // Current state of the building

public:
    // Virtual Destructor
    virtual ~Building() = default;

    // Pure Virtual Functions - Must be implemented by derived classes
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
