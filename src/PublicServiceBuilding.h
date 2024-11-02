#include "Buildings.h"
#include <string>
using namespace std;

#ifndef PUBLICSERVICEBUILDING_H
#define PUBLICSERVICEBUILDING_H

/**
 * @brief Abstract base class representing public service buildings in the simulation
 * @details This class extends the Buildings base class and implements specific
 *          functionality for public service structures such as Hospital, School,
 *          and Police Station
 */
class PublicServiceBuilding : Buildings {
protected:
    /** @brief Name identifier for the public service building */
    string buildingName;
    
    /** @brief Type category of the service building (e.g., hospital, school, police station) */
    string buildingType;
    
    /** @brief List of citizens working at or being served by this facility */
    Citizen* listOfCitizens;
    
    /** @brief Monthly maintenance cost for the public service facility */
    double maintenanceCost;
    
    /** @brief Power requirement for the building in units */
    int powerReq;
    
    /** @brief Water requirement for the building in units */
    int waterReq;
    
    /** @brief Sewage cost for the building in units */
    int sewageCost;
    
    /** @brief Mediator for handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Pointer to the state object managing this public service building */
    State* state;

public:
    /**
     * @brief Handles sewage cleaning for the public service building
     * @return true if sewage was successfully cleaned, false otherwise
     */
    virtual bool cleanSewage() = 0;
    
    /**
     * @brief Handles waste cleaning for the public service building
     * @return true if waste was successfully cleaned, false otherwise
     */
    virtual bool cleanWaste() = 0;
    
    /**
     * @brief Gets the type of the public service building
     * @return Building type as string (e.g., "Hospital", "School", "Police Station")
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the water cost of the public service building
     * @return Water cost in units
     */
    virtual int getWaterCost() = 0;
    
    /**
     * @brief Gets the number of jobs created by this public service facility
     * @return Number of jobs as integer (includes administrative and service staff)
     */
    virtual int getJobsCreated() = 0;
    
    /**
     * @brief Gets the maintenance cost of the public service building
     * @return Monthly maintenance cost in currency units
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the name of the public service building
     * @return Building name as string
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the power requirement of the public service building
     * @return Power requirement in units
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the public service building
     * @return Sewage cost in units
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Main operation function for the public service building
     * @details Handles primary operations including service delivery,
     *          resource management, and citizen service coordination
     */
    virtual void operation() = 0;
    
    /**
     * @brief Processes maintenance payment for the public service building
     * @return true if maintenance was successfully paid, false otherwise
     */
    virtual bool payMaintenance() = 0;
    
    /**
     * @brief Handles power reception for the public service building
     * @return true if power was successfully received, false otherwise
     */
    virtual bool receivePower() = 0;
    
    /**
     * @brief Handles water reception for the public service building
     * @return true if water was successfully received, false otherwise
     */
    virtual bool receiveWater() = 0;
    
    /**
     * @brief Requests the current state of the public service building
     */
    virtual void requestState() = 0;
};

#endif
