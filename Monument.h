#include "LandmarkBuilding.h"
#include <string>
using namespace std;

#ifndef MONUMENT_H
#define MONUMENT_H

/**
 * @class Monument
 * @brief Represents a monument, inheriting from LandmarkBuilding.
 */
class Monument : public LandmarkBuilding {

    // Basic building details
    string buildingName;          /**< Name of the monument. */
    string buildingType;          /**< Type of the monument. */
    Citizen* listOfCitizens;      /**< List of citizens associated with the monument. */

    // Resource and cost requirements
    double maintenanceCost;       /**< Maintenance cost for the monument. */
    int powerReq;                 /**< Power requirement of the monument. */
    int waterReq;                 /**< Water requirement of the monument. */
    int sewageCost;               /**< Sewage cost for the monument. */
    int waste;                    /**< Waste produced by the monument. */

    // Mediator and state objects
    ResourceMediator* resources;  /**< Mediator for managing resources. */
    State* state;                 /**< Current state of the monument. */

public:
    /**
     * @brief Constructs a Monument object.
     * @param bName Name of the monument.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     */
    Monument(string bName,int pReq, int wReq, double mCost, int sCost, int waste);

    /**
     * @brief Cleans the sewage of the monument.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the monument.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the monument.
     * @return The type of the monument as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the monument.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the monument.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the monument.
     * @return The name of the monument as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the monument.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the monument.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the monument.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Pays the maintenance cost for the monument.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the monument.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the monument.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the monument.
     */
    virtual void requestState();

    /**
     * @brief Gets the waste cost for the monument.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

    /**
     * @brief Sets the state of the monument.
     */
    void setState();
};

#endif

