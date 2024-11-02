#include "Buildings.h"
#include <string>
using namespace std;

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

// Forward declarations
class Citizen;
class ResourceMediator;
class State;

/**
 * @brief Abstract base class representing landmark buildings in the simulation
 * @details This class extends the Buildings base class and implements specific
 *          functionality for landmark structures such as Park , Monument and Cultural Center
 */
class LandmarkBuilding : Buildings {
protected:
    /** @brief Name identifier for the landmark building */
    string buildingName;
    
    /** @brief Type category of the landmark (e.g., monument, museum, historical site) */
    string buildingType;
    
    /** @brief List of citizens working at or visiting this landmark */
    Citizen* listOfCitizens;
    
    /** @brief Monthly maintenance cost for preserving the landmark */
    double maintenanceCost;
    
    /** @brief Power requirement for the landmark in units */
    int powerReq;
    
    /** @brief Water requirement for the landmark in units */
    int waterReq;
    
    /** @brief Sewage cost for the landmark in units */
    int sewageCost;
    
    /** @brief Mediator for handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Pointer to the state object managing this landmark */
    State* state;

public:
    /**
     * @brief Handles sewage cleaning for the landmark building
     * @return true if sewage was successfully cleaned, false otherwise
     */
    virtual bool cleanSewage() = 0;
    
    /**
     * @brief Handles waste cleaning for the landmark building
     * @return true if waste was successfully cleaned, false otherwise
     */
    virtual bool cleanWaste() = 0;
    
    /**
     * @brief Gets the type of the landmark building
     * @return Building type as string (e.g., "Monument", "Museum", "Historical Site")
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the number of jobs created by this landmark
     * @return Number of jobs as integer (typically includes tourism and maintenance staff)
     */
    virtual int getJobsCreated() = 0;
    
    /**
     * @brief Gets the maintenance cost of the landmark building
     * @return Monthly maintenance cost in currency units (often higher due to preservation needs)
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the name of the landmark building
     * @return Building name as string
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the power requirement of the landmark building
     * @return Power requirement in units
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the landmark building
     * @return Sewage cost in units
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Gets the water cost of the landmark building
     * @return Water cost in units
     */
    virtual int getWaterCost() = 0;
    
    /**
     * @brief Main operation function for the landmark building
     * @details Handles primary landmark operations including visitor management,
     *          maintenance of historical/cultural value, and resource management
     */
    virtual void operation() = 0;
    
    /**
     * @brief Processes maintenance payment for the landmark building
     * @return true if maintenance was successfully paid, false otherwise
     */
    virtual bool payMaintenance() = 0;
    
    /**
     * @brief Handles power reception for the landmark building
     * @return true if power was successfully received, false otherwise
     */
    virtual bool receivePower() = 0;
    
    /**
     * @brief Handles water reception for the landmark building
     * @return true if water was successfully received, false otherwise
     */
    virtual bool receiveWater() = 0;
    
    /**
     * @brief Requests the current state of the landmark building
     */
    virtual void requestState() = 0;
};

#endif
