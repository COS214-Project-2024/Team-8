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
class Buildings
{
protected:
    double profit;
    double sales;
    double balance;

public:
    State *state; /**< Pointer to the state of the building. */

protected:
    /**< Pointer to the resource mediator for managing resources. */
    int powerReq;            /**< Power requirement of the building. */
    int waterReq;            /**< Water requirement of the building. */
    int sewageCost;          /**< Sewage cost associated with the building. */
    double maintenanceCost;  /**< Maintenance cost of the building. */
    string buildingName;     /**< Name of the building. */
    string buildingType;     /**< Type of the building. */
    Citizen *listOfCitizens; /**< List of citizens associated with the building. */

public:
    ResourceMediator *resources;
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
    virtual void setState(State *newState) = 0;

    /**
     * @brief Returns the list of residents in a building
     * @return list of residents in the building
     */
    Citizen *getlistOfResidence()
    {
        return this->listOfCitizens;
    }

    /**
     * @brief sets the resource mediator of the class
     */
    void setResources(ResourceMediator *resources)
    {
        this->resources = resources;
    }
    // Setters
    void setProfit(double newProfit) { profit = newProfit; }
    void setSales(double newSales) { sales = newSales; }
    void setBalance(double newBalance) { balance = newBalance; }

    // Getters
    double getProfit() const { return profit; }
    double getSales() const { return sales; }
    double getBalance() const { return balance; }
};

#endif
