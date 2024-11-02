#include "Buildings.h"
#include <string>
using namespace std;

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

/**
 * @brief Abstract base class representing residential buildings in the simulation
 * @details This class extends the Buildings base class and implements specific
 *          functionality for residential structures such as Townhouse , Apartment and House
 */
class ResidentialBuilding : Buildings {
protected:
    /** @brief Name identifier for the residential building */
    string buildingName;
    
    /** @brief Type category of the residential building */
    string buildingType;
    
    /** @brief List of citizens residing in this building */
    Citizen* listOfCitizens;
    
    /** @brief Monthly maintenance cost for the building */
    double maintenanceCost;
    
    /** @brief Power requirement for the building in units */
    int powerReq;
    
    /** @brief Water requirement for the building in units */
    int waterReq;
    
    /** @brief Sewage cost for the building in units */
    int sewageCost;
    
    /** @brief Maximum number of citizens that can reside in the building */
    int capacity;
    
    /** @brief Mediator for handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Pointer to the state object managing this building */
    State* state;

public:
    /**
     * @brief Handles sewage cleaning for the residential building
     * @return true if sewage was successfully cleaned, false otherwise
     */
    virtual bool cleanSewage() = 0;
    
    /**
     * @brief Handles waste cleaning for the residential building
     * @return true if waste was successfully cleaned, false otherwise
     */
    virtual bool cleanWaste() = 0;
    
    /**
     * @brief Gets the type of the residential building
     * @return Building type as string
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the number of jobs created by this residential building
     * @return Number of jobs as integer (typically 0 for residential buildings)
     */
    virtual int getJobsCreated() = 0;
    
    /**
     * @brief Gets the maintenance cost of the residential building
     * @return Monthly maintenance cost in currency units
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the name of the residential building
     * @return Building name as string
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the power requirement of the residential building
     * @return Power requirement in units
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the residential building
     * @return Sewage cost in units
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Gets the water cost of the residential building
     * @return Water cost in units
     */
    virtual int getWaterCost() = 0;
    
    /**
     * @brief Main operation function for the residential building
     * @details Handles primary residential operations including resource consumption
     *          and citizen management
     */
    virtual void operation() = 0;
    
    /**
     * @brief Processes maintenance payment for the residential building
     * @return true if maintenance was successfully paid, false otherwise
     */
    virtual bool payMaintenance() = 0;
    
    /**
     * @brief Handles power reception for the residential building
     * @return true if power was successfully received, false otherwise
     */
    virtual bool receivePower() = 0;
    
    /**
     * @brief Handles water reception for the residential building
     * @return true if water was successfully received, false otherwise
     */
    virtual bool receiveWater() = 0;
    
    /**
     * @brief Requests the current state of the residential building
     */
    virtual void requestState() = 0;
};

#endif
