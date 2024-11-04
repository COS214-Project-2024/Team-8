/**
 * @file Buildings.h
 * @brief Header file containing the Buildings abstract base class definition
 * @author Design Wits
 * @date 2024-04-29
 */

#include <string>
#include "Utility.h"

using namespace std;
#ifndef BUILDINGS_H
#define BUILDINGS_H

class State;
class Citizen;

/**
 * @class Buildings
 * @brief Abstract base class representing a building with basic utilities and resource requirements.
 * 
 * This class serves as the foundation for all building types in the city simulation,
 * defining common attributes and interfaces for resource management and state handling.
 */
class Buildings
{
protected:
    double profit;
    double sales;
    double balance;

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
    Utility* resources; /**< Mediator for handling resource distribution. */

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
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual double getBalance(){return 0;}

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual void setBalance(double b){std::cout<<"No\n";}

    /**
     * @brief Pays a citizen employed in the building.
     * @return The payment amount as an integer.
     */
    virtual int payCitizen(){return 0;}

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
	 * @brief Add a building to the Utility resource
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding() = 0;

    /**
     * @brief Gets the number of jobs created by the building.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated(){return 0;}

    /**
     * @brief Receives power for the building.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool getPower() = 0;

    /**
     * @brief Receives water for the building.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool getWater() = 0;

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
    virtual void setState(State *newState) = 0;

    /**
     * @brief Returns the list of residents in a building.
     * @return Pointer to the list of citizens residing in or associated with the building.
     */
    virtual Citizen* getlistOfResidence() {
        return this->listOfCitizens;
    }

    /**
     * @brief Gets the sales generated by the commercial building.
     * @return Sales amount as a float.
     */
    virtual float getSales(){return 0;}

    /**
     * @brief Gets the profit generated by the commercial building.
     * @return Profit amount as a float.
     */
    virtual float getProfit(){return 0;}

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual int getCommercialIncome(){return 0;}

    /**
     * @brief Sets the resource mediator for the building.
     * @param resources Pointer to the Utility object to be used.
     */
    void setResources(Utility* resources) {
        this->resources = resources;
    }

    /**
     * @brief Gets the security coverage provided by the police station.
     * @return The security coverage as a float.
     */
    virtual float getEducationalCoverage(){return 0;}

    /**
     * @brief Gets the security coverage provided by the police station.
     * @return The security coverage as a float.
     */
    virtual float getSecurityCoverage(){return 0;}

    /**
     * @brief Gets the waste cost of the building.
     * @return Waste cost as an integer.
     */
    virtual int getWasteCost(){return 0;}

     /**
     * @brief Gets the health coverage provided by the medical center.
     * @return The health coverage as a float.
     */
    virtual float getHealthCoverage(){return 0;}

    /**
     * @brief Gets the birth rate supported by the medical center.
     * @return The birth rate as an integer.
     */
    virtual int getBirthRate();

    virtual ~Buildings(){ delete listOfCitizens; delete state; listOfCitizens = nullptr;}
};

#endif // BUILDINGS_H