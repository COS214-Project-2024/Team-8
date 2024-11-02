#include "ResidentialBuilding.h"
#include <string>
using namespace std;

#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

/**
 * @brief A class representing a residential townhouse building
 * @details Inherits from ResidentialBuilding and implements residential building operations
 *          including resource management, maintenance, and citizen housing
 */
class TownHouse : ResidentialBuilding {
protected:
    /** @brief Name identifier for the townhouse */
    string buildingName;
    
    /** @brief Type identifier for the building */
    string buildingType;
    
    /** @brief Maximum number of citizens that can reside in the townhouse */
    int capacity;
    
    /** @brief Pointer to array of citizens currently residing in the townhouse */
    Citizen* listOfCitizens;
    
    /** @brief Monthly cost for maintaining the townhouse */
    double maintenanceCost;
    
    /** @brief Power requirement in units per month */
    int powerReq;
    
    /** @brief Water requirement in units per month */
    int waterReq;
    
    /** @brief Cost for sewage processing per month */
    int sewageCost;
    
    /** @brief Amount of waste produced per month */
    int waste;
    
    /** @brief Pointer to resource mediator handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Pointer to current state of the building */
    State* state;

public:
    /**
     * @brief Constructor for TownHouse
     * @param bName Name of the townhouse
     * @param pReq Power requirement
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Waste production
     * @param capacity Maximum number of residents
     */
    TownHouse(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int capacity);

    /**
     * @brief Process sewage for the townhouse
     * @return True if sewage was successfully processed, false otherwise
     */
    virtual bool cleanSewage();

    /**
     * @brief Process waste for the townhouse
     * @return True if waste was successfully processed, false otherwise
     */
    virtual bool cleanWaste();

    /**
     * @brief Get the type of building
     * @return String indicating building type
     */
    virtual string getBuildingType();

    /**
     * @brief Get number of jobs created by this building
     * @return Number of jobs created
     */
    virtual int getJobsCreated();

    /**
     * @brief Get monthly maintenance cost
     * @return Maintenance cost as double
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Get building name
     * @return Building name as string
     */
    virtual string getName();

    /**
     * @brief Get power requirement
     * @return Power requirement in units
     */
    virtual int getPowerReq();

    /**
     * @brief Get sewage processing cost
     * @return Sewage cost in currency units
     */
    virtual int getSewageCost();

    /**
     * @brief Get water requirement
     * @return Water requirement in units
     */
    virtual int getWaterReq();

    /**
     * @brief Perform building operations
     */
    virtual void operation();

    /**
     * @brief Process maintenance payment
     * @return True if maintenance was paid successfully, false otherwise
     */
    virtual bool payMaintenance();

    /**
     * @brief Process power reception
     * @return True if power was received successfully, false otherwise
     */
    virtual bool receivePower();

    /**
     * @brief Process water reception
     * @return True if water was received successfully, false otherwise
     */
    virtual bool receiveWater();

    /**
     * @brief Request current state of building
     */
    virtual void requestState();

    /**
     * @brief Set building state
     */
    void setState();

    /**
     * @brief Get waste processing cost
     * @return Waste cost in currency units
     */
    int getWasteCost();

    /**
     * @brief Get maximum resident capacity
     * @return Maximum number of residents
     */
    int getCapacity();

    /**
     * @brief Get list of current residents
     * @return Pointer to array of Citizen objects
     */
    Citizen* getListOfResidents();
};

#endif
