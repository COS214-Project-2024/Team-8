#include "ResidentialBuilding.h"
#include <string>

using namespace std;

#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

/**
 * @class TownHouse
 * @brief Represents a townhouse, a type of residential building.
 */
class TownHouse : public ResidentialBuilding {

protected:
    // Building details
    string buildingName; ///< The name of the townhouse
    string buildingType; ///< The type of building
    int capacity; ///< The maximum capacity of the townhouse
    Citizen* listOfCitizens; ///< Pointer to the list of residents

    // Resource and maintenance requirements
    double maintenanceCost; ///< The cost of maintenance
    int powerReq; ///< The power requirement
    int waterReq; ///< The water requirement
    int sewageCost; ///< The sewage cost
    int waste; ///< The amount of waste produced

    // Mediator and state
    Utility* resources; ///< Pointer to the resource mediator
    State* state; ///< Pointer to the current state of the townhouse

public:
    /**
     * @brief Constructor for the TownHouse class.
     * @param bName Name of the townhouse
     * @param pReq Power requirement
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Amount of waste produced
     * @param capacity Maximum capacity of the townhouse
     */
    TownHouse(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int capacity);
    
    /**
     * @brief Gets the type of building.
     * @return The building type as a string.
     */
    virtual string getBuildingType();
    
    /**
     * @brief Gets the number of jobs created by the townhouse.
     * @return The number of jobs created.
     */
    virtual int getJobsCreated();
    
    /**
     * @brief Gets the maintenance cost of the townhouse.
     * @return The maintenance cost.
     */
    virtual double getMaintenanceCost();
    
    /**
     * @brief Gets the name of the townhouse.
     * @return The name of the townhouse as a string.
     */
    virtual string getName();
    
    /**
     * @brief Gets the power requirement of the townhouse.
     * @return The power requirement.
     */
    virtual int getPowerReq();
    
    /**
     * @brief Gets the sewage cost of the townhouse.
     * @return The sewage cost.
     */
    virtual int getSewageCost();
    
    /**
     * @brief Gets the water requirement of the townhouse.
     * @return The water requirement.
     */
    virtual int getWaterReq();
    
    /**
     * @brief Requests the current state of the townhouse.
     */
    virtual void requestState();
    
    /**
     * @brief Gets the list of residents in the townhouse.
     * @return Pointer to the list of residents.
     */
    Citizen* getListOfResidents();
    
    /**
     * @brief Gets the maximum capacity of the townhouse.
     * @return The capacity of the townhouse.
     */
    int getCapacity();
    
    /**
     * @brief Gets the waste cost associated with the townhouse.
     * @return The waste cost.
     */
    int getWasteCost();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);
};

#endif

