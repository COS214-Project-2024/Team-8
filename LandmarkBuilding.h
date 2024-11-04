#include "Buildings.h"
#include <string>
using namespace std;

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

/**
 * @class LandmarkBuilding
 * @brief Represents a landmark building, inheriting from Buildings.
 */
class LandmarkBuilding : public Buildings {

protected:
    string buildingName;          /**< Name of the landmark building. */
    string buildingType;          /**< Type of the landmark building. */
    Citizen* listOfCitizens;      /**< List of citizens associated with the building. */

    double maintenanceCost;       /**< Maintenance cost for the building. */
    int powerReq;                 /**< Power requirement of the building. */
    int waterReq;                 /**< Water requirement of the building. */
    int sewageCost;               /**< Sewage cost for the building. */

    ResourceMediator* resources;  /**< Mediator for managing resources. */
    State* state;                 /**< Current state of the building. */

public:

    /**
     * @brief Gets the type of the landmark building.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Gets the number of jobs created by the landmark building.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated() = 0;

    /**
     * @brief Gets the maintenance cost of the landmark building.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Gets the name of the landmark building.
     * @return The name of the building as a string.
     */
    virtual string getName() = 0;

    /**
     * @brief Gets the power requirement of the landmark building.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Gets the sewage cost of the landmark building.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Gets the water requirement of the landmark building.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq() = 0;

    /**
     * @brief Requests the current state of the landmark building.
     */
    virtual void requestState() = 0;

    /**
     * @brief sets the state of the building
     */
    virtual void setState(State* newState) = 0;

};

#endif

