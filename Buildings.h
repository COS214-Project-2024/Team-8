/**
 * @file Buildings.h
 * @brief Header file containing the Buildings abstract base class definition
 * @author Design Wits
 * @date 2024-04-29
 */

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
 * 
 * This class serves as the foundation for all building types in the city simulation,
 * defining common attributes and interfaces for resource management and state handling.
 */
class Buildings {
public:
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     * 
     * This virtual destructor is necessary because the class hierarchy uses polymorphism
     * and objects may be deleted through pointers to the base class.
     */
    virtual ~Buildings() = default;

    State* state; /**< Pointer to the state of the building. */

protected:
     /**< Pointer to the resource mediator for managing resources. */
    int powerReq;                /**< Power requirement of the building in kWh. */
    int waterReq;                /**< Water requirement of the building in liters. */
    int sewageCost;              /**< Sewage cost associated with the building in currency units. */
    double maintenanceCost;      /**< Maintenance cost of the building in currency units. */
    string buildingName;         /**< Name of the building for identification. */
    string buildingType;         /**< Type of the building (e.g., residential, commercial). */
    Citizen* listOfCitizens;     /**< List of citizens associated with the building. */

public:
    ResourceMediator* resources; /**< Mediator for handling resource distribution. */

    /**
     * @brief Requests the current state of the building.
     * @note Pure virtual function to be implemented by derived classes.
     */
    virtual void requestState() = 0;

    /**
     * @brief Retrieves the maintenance cost of the building.
     * @return The maintenance cost as a double, representing currency units.
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Retrieves the power requirement of the building.
     * @return The power requirement in kilowatt-hours (kWh).
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Retrieves the sewage cost of the building.
     * @return The sewage cost in currency units.
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Retrieves the water requirement of the building.
     * @return The water requirement in liters.
     */
    virtual int getWaterReq() = 0;

    /**
     * @brief Retrieves the name of the building.
     * @return The building's name as a string.
     */
    virtual string getName() = 0;

    /**
     * @brief Retrieves the type of the building.
     * @return The building type as a string (e.g., "residential", "commercial").
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Retrieves the number of jobs created by the building.
     * @return The number of employment positions created.
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
     * @param newState Pointer to the new state object to be assigned.
     */
    virtual void setState(State* newState) = 0;

    /**
     * @brief Returns the list of residents in a building.
     * @return Pointer to the list of citizens residing in or associated with the building.
     */
    Citizen* getlistOfResidence() {
        return this->listOfCitizens;
    }
 
    /**
     * @brief Sets the resource mediator for the building.
     * @param resources Pointer to the ResourceMediator object to be used.
     */
    void setResources(ResourceMediator* resources) {
        this->resources = resources;
    }
};

#endif // BUILDINGS_H