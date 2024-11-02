#include "Buildings.h"
#include <string>
using namespace std;

#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

// Forward declarations
class Citizen;
class ResourceMediator;
class State;

/**
 * @brief Abstract base class representing industrial buildings in the simulation
 * @details This class extends the Buildings base class and implements specific
 *          functionality for industrial structures Powerplant , Warehouse and Fcatory
 */
class IndustrialBuilding : Buildings {
protected:
    /** @brief Name identifier for the industrial building */
    string buildingName;
    
    /** @brief Type category of the industrial building */
    string buildingType;
    
    /** @brief List of citizens working in or associated with this building */
    Citizen* listOfCitizens;
    
    /** @brief Monthly maintenance cost for the building */
    double maintenanceCost;
    
    /** @brief Power requirement for the building in units (typically higher for industrial) */
    int powerReq;
    
    /** @brief Water requirement for the building in units */
    int waterReq;
    
    /** @brief Sewage cost for the building in units */
    int sewageCost;
    
    /** @brief Mediator for handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Total sales revenue generated by the industrial operation */
    float sales;
    
    /** @brief Net profit after deducting manufacturing and operational costs */
    float profit;
    
    /** @brief Number of workers currently employed in the facility */
    int employment;
    
    /** @brief Pointer to the state object managing this building */
    State* state;

public:
    /**
     * @brief Handles sewage cleaning for the industrial building
     * @return true if industrial waste water was successfully processed, false otherwise
     */
    virtual bool cleanSewage() = 0;
    
    /**
     * @brief Handles industrial waste cleaning and disposal
     * @return true if industrial waste was successfully processed, false otherwise
     */
    virtual bool cleanWaste() = 0;
    
    /**
     * @brief Gets the type of the industrial building
     * @return Building type as string (e.g., "Factory", "Warehouse")
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the number of jobs created by this industrial facility
     * @return Number of jobs as integer
     */
    virtual int getJobsCreated() = 0;
    
    /**
     * @brief Gets the maintenance cost of the industrial building
     * @return Monthly maintenance cost in currency units
     */
    virtual double getMaintenanceCost() = 0;
    
    /**
     * @brief Gets the name of the industrial building
     * @return Building name as string
     */
    virtual string getName() = 0;
    
    /**
     * @brief Gets the power requirement of the industrial building
     * @return Power requirement in units
     */
    virtual int getPowerReq() = 0;
    
    /**
     * @brief Gets the sewage cost of the industrial building
     * @return Sewage processing cost in units
     */
    virtual int getSewageCost() = 0;
    
    /**
     * @brief Gets the water cost of the industrial building
     * @return Water cost in units
     */
    virtual int getWaterCost() = 0;
    
    /**
     * @brief Main operation function for the industrial building
     * @details Handles primary industrial operations including manufacturing,
     *          resource management, and worker coordination
     */
    virtual void operation() = 0;
    
    /**
     * @brief Processes maintenance payment for the industrial building
     * @return true if maintenance was successfully paid, false otherwise
     */
    virtual bool payMaintenance() = 0;
    
    /**
     * @brief Handles power reception for the industrial building
     * @return true if power was successfully received, false otherwise
     */
    virtual bool receivePower() = 0;
    
    /**
     * @brief Handles water reception for the industrial building
     * @return true if water was successfully received, false otherwise
     */
    virtual bool receiveWater() = 0;
    
    /**
     * @brief Requests the current state of the industrial building
     */
    virtual void requestState() = 0;

    // Additional industrial-specific functions
    
    /**
     * @brief Gets the total sales revenue of the industrial operation
     * @return Total sales in currency units
     */
    float getSales();
    
    /**
     * @brief Secondary operation function for additional industrial processes
     * @details Handles supplementary operations such as maintenance cycles,
     *          inventory management, or specialized production runs
     */
    void operation2();
    
    /**
     * @brief Gets the net profit of the industrial operation
     * @return Net profit in currency units
     */
    float getProfit();
};

#endif
