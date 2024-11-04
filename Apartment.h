#include <string>
using namespace std;

#ifndef APARTMENT_H
#define APARTMENT_H

class ResourceMediator;
class Citizen;
#include "ResidentialBuilding.h"

/**
 * @class Apartment
 * @brief Represents an apartment building that inherits from ResidentialBuilding.
 */
class Apartment : public ResidentialBuilding {

protected:
    string buildingName;      /**< The name of the building. */
    string buildingType;      /**< The type of the building. */
    int capacity;             /**< The capacity of the building in terms of residents. */
    Citizen* listOfCitizens;  /**< List of residents in the apartment. */

    double maintenanceCost;   /**< The maintenance cost of the building. */
    int powerReq;             /**< Power requirement of the building. */
    int waterReq;             /**< Water requirement of the building. */
    int sewageCost;           /**< Sewage cost for the building. */
    int waste;                /**< Waste generated by the building. */

    ResourceMediator* resources; /**< Mediator for managing resources for the building. */
    State* state;             /**< State of the building. */

public:
    /**
     * @brief Constructs an Apartment object with the specified attributes.
     * @param bName The name of the building.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste generated by the building.
     * @param capacity The capacity in terms of residents.
     */
    Apartment(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int capacity);

    /**
     * @brief Cleans the sewage of the building.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the building.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the building.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the building.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the building.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the building.
     * @return The name of the building as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the building.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the building.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the building.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Requests the state of the building.
     */
    virtual void requestState();

    /**
     * @brief Gets the list of residents in the apartment.
     * @return A pointer to the list of residents.
     */
    Citizen* getListOfResidents();

    /**
     * @brief Gets the capacity of the building.
     * @return The capacity as an integer.
     */
    int getCapacity();

    /**
     * @brief Gets the waste cost of the building.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);
};

#endif
