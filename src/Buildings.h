#include <exception>
using namespace std;

#ifndef __Buildings_h__
#define __Buildings_h__

#include "State.h"
// #include "Government.h"
// #include "ConstructionCompany.h"
// #include "Resources.h"

class Government;         // Forward declaration
class ConstructionCompany; // Forward declaration
class Resources;          // Forward declaration

class Buildings // Correct class declaration without 'public'
{
private:
    //State _state;          // Assuming State is a class and needs to be instantiated
    int _powerReq;
    int _waterReq;
    double _maintenanceCost;
    int _sewageCost;
    int _waste;

public:
    Government* _unnamed_Government_;
    ConstructionCompany* _unnamed_ConstructionCompany_;
    State* _building;      // Fix typo from _buidling to _building
    Resources* _unnamed_Resources_;

    // Virtual methods
    virtual void requestState() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual int getPowerReq() = 0;
    virtual int getSewageCost() = 0;
    virtual int getWaterCost() = 0;
    virtual int getWasteCost() = 0; // Correct return type to match your intention
};

#endif
