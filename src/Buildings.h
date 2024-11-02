#include <string>
using namespace std;

#ifndef BUILDINGS_H
#define BUILDINGS_H

// Forward declarations
class State;
class ResourceMediator;
class Citizen;

/**
 * @brief Abstract base class representing buildings in a city simulation system
 * @details This class defines the interface for all building types in the simulation : 
 *        Residential , Commercial , Industrial , Landmarks , Public Service 
 */
class Buildings {
public:
    /** @brief Pointer to the state object managing a type of building */
    State* state;

protected:
    /** @brief Mediator for handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Power requirement for the building in units */
    int powerReq;
    
    /** @brief Water requirement for the building in units */
    int waterReq;
    
    /** @brief Sewage cost for the building in units */
    int sewageCost;
    
    /** @brief Monthly maintenance cost for the building */
    double maintenanceCost;
    
    /** @brief Name identifier for the building */
    string buildingName;
    
    /** @brief Type category of the building */
    string buildingType;
    
    /** @brief List of citizens associated with this building */
    Citizen* listOfCitizens;

public:
    // Pure virtual functions to be implemented by derived classes
    
    /**
     * @brief Requests the current state of the building
     */
    virtual void requestState() = 0;
    
    /**
     * @brief Gets the maintenance cost of the building
     * @return Monthly maintenance cost in currency units
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the power requirement of the building
     * @return Power requirement in units
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the building
     * @return Sewage cost in units
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Gets the water cost of the building
     * @return Water cost in units
     */
    virtual int getWaterCost() = 0;
    
    /**
     * @brief Gets the name of the building
     * @return Building name as string
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the type of the building
     * @return Building type as string
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the number of jobs created by this building
     * @return Number of jobs as integer
     */
    virtual int getJobsCreated() = 0;

    // Resource management functions
    
    /**
     * @brief Handles power reception for the building
     * @return true if power was successfully received, false otherwise
     */
    virtual bool receivePower() = 0;
    
    /**
     * @brief Handles water reception for the building
     * @return true if water was successfully received, false otherwise
     */
    virtual bool receiveWater() = 0;
    
    /**
     * @brief Processes maintenance payment
     * @return true if maintenance was successfully paid, false otherwise
     */
    virtual bool payMaintenance() = 0;
    
    /**
     * @brief Handles waste cleaning for the building
     * @return true if waste was successfully cleaned, false otherwise
     */
    virtual bool cleanWaste() = 0;
    
    /**
     * @brief Handles sewage cleaning for the building
     * @return true if sewage was successfully cleaned, false otherwise
     */
    virtual bool cleanSewage() = 0;

    /**
     * @brief Main operation function for the building
     * @details This function handles the main operational logic specific to each building type
     */
    virtual void operation() = 0;
};

#endif
