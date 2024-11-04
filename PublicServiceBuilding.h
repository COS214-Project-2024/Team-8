#include "Buildings.h"
#include <string>
using namespace std;

#ifndef PUBLICSERVICEBUILDING_H
#define PUBLICSERVICEBUILDING_H

/**
 * @class PublicServiceBuilding
 * @brief Abstract class representing a public service building, inheriting from Buildings.
 */
class PublicServiceBuilding : public Buildings {

protected:
    // Building details
    string buildingName; ///< Name of the building
    string buildingType; ///< Type of the building
    Citizen* listOfCitizens; ///< List of citizens associated with the building

    // Resource and maintenance requirements
    double maintenanceCost; ///< Cost required for maintenance
    int powerReq; ///< Power requirement for the building
    int waterReq; ///< Water requirement for the building
    int sewageCost; ///< Sewage cost for the building
    int waste; ///< Waste generated by the building

    // Resource mediator and state
    ResourceMediator* resources; ///< Mediator for resources
    State* state; ///< Current state of the building

public:
    // Pure virtual functions for building operations
    
    /**
     * @brief Gets the type of building.
     * @return Type of the building as a string.
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the water requirement of the building.
     * @return Water requirement as an integer.
     */
    virtual int getWaterReq() = 0;
    
    /**
     * @brief Gets the number of jobs created by the building.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated() = 0;
    
    /**
     * @brief Gets the maintenance cost of the building.
     * @return Maintenance cost as a double.
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the name of the building.
     * @return Name of the building as a string.
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the power requirement of the building.
     * @return Power requirement as an integer.
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the building.
     * @return Sewage cost as an integer.
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Requests the current state of the building.
     */
    virtual void requestState() = 0;

    /**
     * @brief sets the state of the building
     */
    virtual void setState(State* newState) = 0;
    
    /**
     * @brief Gets the waste cost of the building.
     * @return Waste cost as an integer.
     */
    int getWasteCost();
};

#endif

