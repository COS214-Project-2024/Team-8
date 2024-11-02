/**
 * @file Park.h
 * @brief Header file for the Park class, which inherits from LandmarkBuilding.
 */

#include "LandmarkBuilding.h" 
#include <string>
using namespace std;

#ifndef PARK_H
#define PARK_H

/**
 * @class Park
 * @brief Represents a park building, inheriting from LandmarkBuilding.
 */
class Park : LandmarkBuilding {

    // Basic building details
    string buildingName;       /**< Name of the park building */
    string buildingType;       /**< Type of the building */
    Citizen* listOfCitizens;   /**< Pointer to a list of citizens associated with the building */

    // Resource and cost requirements
    double maintenanceCost;    /**< Cost of maintenance for the park */
    int powerReq;              /**< Power requirement for the park */
    int waterReq;              /**< Water requirement for the park */
    int sewageCost;            /**< Cost associated with sewage maintenance for the park */

    // Mediator and state objects
    ResourceMediator* resources; /**< Resource mediator associated with the park */
    State* state;                /**< Current state of the park */

public:
    // Pure virtual functions for building operations

    /**
     * @brief Cleans the sewage of the park.
     * @return true if successful, otherwise false
     */
    virtual bool cleanSewage() = 0;

    /**
     * @brief Cleans the waste of the park.
     * @return true if successful, otherwise false
     */
    virtual bool cleanWaste() = 0;

    /**
     * @brief Gets the type of the building.
     * @return A string representing the building type
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Gets the number of jobs created by the park.
     * @return Number of jobs created
     */
    virtual int getJobsCreated() = 0;

    /**
     * @brief Gets the maintenance cost of the park.
     * @return Maintenance cost as a double
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Gets the name of the park.
     * @return Name of the park as a string
     */
    virtual string getName() = 0;

    /**
     * @brief Gets the power requirement of the park.
     * @return Power requirement as an integer
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Gets the sewage cost for the park.
     * @return Sewage cost as an integer
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Gets the water cost for the park.
     * @return Water cost as an integer
     */
    virtual int getWaterCost() = 0;

    /**
     * @brief Performs an operation in the park.
     */
    virtual void operation() = 0;

    /**
     * @brief Pays the maintenance cost of the park.
     * @return true if successful, otherwise false
     */
    virtual bool payMaintenance() = 0;

    /**
     * @brief Receives power for the park.
     * @return true if successful, otherwise false
     */
    virtual bool receivePower() = 0;

    /**
     * @brief Receives water for the park.
     * @return true if successful, otherwise false
     */
    virtual bool receiveWater() = 0;

    /**
     * @brief Requests the current state of the park.
     */
    virtual void requestState() = 0;

};

#endif 
