/**
 * @file Monument.h
 * @brief Header file for the Monument class, which inherits from LandmarkBuilding.
 */

#include "LandmarkBuilding.h" 
#include <string>
using namespace std;

#ifndef MONUMENT_H
#define MONUMENT_H

/**
 * @class Monument
 * @brief Represents a monument building, inheriting from LandmarkBuilding.
 */
class Monument : LandmarkBuilding {

    // Basic building details
    string buildingName;       /**< Name of the monument building */
    string buildingType;       /**< Type of the building */
    Citizen* listOfCitizens;   /**< Pointer to a list of citizens associated with the building */

    // Resource and cost requirements
    double maintenanceCost;    /**< Cost of maintenance for the monument */
    int powerReq;              /**< Power requirement for the monument */
    int waterReq;              /**< Water requirement for the monument */
    int sewageCost;            /**< Cost associated with sewage maintenance for the monument */

    // Mediator and state objects
    ResourceMediator* resources; /**< Resource mediator associated with the monument */
    State* state;                /**< Current state of the monument */

public:
    // Pure virtual functions for building operations

    /**
     * @brief Cleans the sewage of the monument.
     * @return true if successful, otherwise false
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the monument.
     * @return true if successful, otherwise false
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the building.
     * @return A string representing the building type
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the monument.
     * @return Number of jobs created
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the monument.
     * @return Maintenance cost as a double
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the monument.
     * @return Name of the monument as a string
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the monument.
     * @return Power requirement as an integer
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost for the monument.
     * @return Sewage cost as an integer
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water cost for the monument.
     * @return Water cost as an integer
     */
    virtual int getWaterCost();

    /**
     * @brief Performs an operation in the monument.
     */
    virtual void operation();

    /**
     * @brief Pays the maintenance cost of the monument.
     * @return true if successful, otherwise false
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the monument.
     * @return true if successful, otherwise false
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the monument.
     * @return true if successful, otherwise false
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the monument.
     */
    virtual void requestState();

};

#endif
