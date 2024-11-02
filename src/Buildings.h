#include <string>
using namespace std;
#ifndef BUILDINGS_H
#define BUILDINGS_H

class State;
class ResourceMediator;
class Citizen;

/**
 * @class Buildings
 * @brief Abstract base class representing a building with basic utilities and resource requirements.
 */
class Buildings {
public:
    State* state; /**< Pointer to the state of the building. */

protected:
    ResourceMediator* resources; /**< Pointer to the resource mediator for managing resources. */
    int powerReq;                /**< Power requirement of the building. */
    int waterReq;                /**< Water requirement of the building. */
    int sewageCost;              /**< Sewage cost associated with the building. */
    double maintenanceCost;      /**< Maintenance cost of the building. */
    string buildingName;         /**< Name of the building. */
    string buildingType;         /**< Type of the building. */
    Citizen* listOfCitizens;     /**< List of citizens associated with the building. */

public:
    /**
     * @brief Requests the current state of the building.
     * @note Pure virtual function to be implemented by derived classes.
     */
    virtual void requestState() = 0;

    /**
     * @brief Retrieves the maintenance cost of the building.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Retrieves the power requirement of the building.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Retrieves the sewage cost of the building.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Retrieves the water requirement of the building.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq() = 0;

    /**
     * @brief Retrieves the name of the building.
     * @return The building's name as a string.
     */
    virtual string getName() = 0;

    /**
     * @brief Retrieves the type of the building.
     * @return The building type as a string.
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Retrieves the number of jobs created by the building.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated() = 0;

    /**
     * @brief Receives power for the building.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool receivePower() = 0;

    /**
     * @brief Receives water for the building.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool receiveWater() = 0;

    /**
     * @brief Pays the maintenance cost of the building.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool payMaintenance() = 0;

    /**
     * @brief Cleans the waste of the building.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste() = 0;

    /**
     * @brief Cleans the sewage of the building.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage() = 0;

    /**
     * @brief Sets the state of the building.
     */
    virtual void setState() = 0;

};

#endif
