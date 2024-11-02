/**
 * @file CulturalCenter.h
 * @brief Header file for the CulturalCenter class, which inherits from LandmarkBuilding.
 */

#include "LandmarkBuilding.h" 
#include <string>
using namespace std;

#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

/**
 * @class CulturalCenter
 * @brief Represents a cultural center building, inheriting from LandmarkBuilding.
 */
class CulturalCenter : LandmarkBuilding {

    // Basic building details
    string buildingName;       /**< Name of the cultural center building */
    string buildingType;       /**< Type of the building */
    Citizen* listOfCitizens;   /**< Pointer to a list of citizens associated with the building */

    // Resource and cost requirements
    double maintenanceCost;    /**< Cost of maintenance for the cultural center */
    int powerReq;              /**< Power requirement for the cultural center */
    int waterReq;              /**< Water requirement for the cultural center */
    int sewageCost;            /**< Cost associated with sewage maintenance for the cultural center */

    // Mediator and state objects
    ResourceMediator* resources; /**< Resource mediator associated with the cultural center */
    State* state;                /**< Current state of the cultural center */

public:
    // Pure virtual functions for building operations

    /**
     * @brief Cleans the sewage of the cultural center.
     * @return true if successful, otherwise false
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the cultural center.
     * @return true if successful, otherwise false
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the building.
     * @return A string representing the building type
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the cultural center.
     * @return Number of jobs created
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the cultural center.
     * @return Maintenance cost as a double
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the cultural center.
     * @return Name of the cultural center as a string
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the cultural center.
     * @return Power requirement as an integer
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost for the cultural center.
     * @return Sewage cost as an integer
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water cost for the cultural center.
     * @return Water cost as an integer
     */
    virtual int getWaterCost();

    /**
     * @brief Performs an operation in the cultural center.
     */
    virtual void operation();

    /**
     * @brief Pays the maintenance cost of the cultural center.
     * @return true if successful, otherwise false
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the cultural center.
     * @return true if successful, otherwise false
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the cultural center.
     * @return true if successful, otherwise false
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the cultural center.
     */
    virtual void requestState();

};

#endif
