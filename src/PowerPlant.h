#include "IndustrialBuilding.h"
#include <string>
using namespace std;

#ifndef POWERPLANT_H
#define POWERPLANT_H

/**
 * @brief A class representing an industrial power plant building
 * @details Inherits from IndustrialBuilding and implements power generation operations,
 *          including resource management, energy production, and environmental impact handling
 */
class PowerPlant : IndustrialBuilding {
protected:
    /** @brief Name identifier for the power plant */
    string buildingName;
    
    /** @brief Type identifier for the building */
    string buildingType;
    
    /** @brief Pointer to array of citizens working at the power plant */
    Citizen* listOfCitizens;
    
    /** @brief Monthly cost for maintaining the power plant */
    double maintenanceCost;
    
    /** @brief Power requirement for internal operations */
    int powerReq;
    
    /** @brief Water requirement for cooling and operations */
    int waterReq;
    
    /** @brief Cost for sewage processing per month */
    int sewageCost;
    
    /** @brief Pointer to resource mediator handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Total revenue from power sales */
    float sales;
    
    /** @brief Net profit after operational expenses */
    float profit;
    
    /** @brief Number of employees operating the plant */
    int employment;
    
    /** @brief Amount of industrial waste produced per month */
    int waste;
    
    /** @brief Pointer to current state of the building */
    State* state;

public:
    /**
     * @brief Constructor for PowerPlant
     * @param bName Name of the power plant
     * @param pReq Power requirement for internal operations
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Waste production rate
     * @param employment Number of required employees
     */
    PowerPlant(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment);

    /**
     * @brief Process industrial sewage from the plant
     * @return True if sewage was successfully processed, false otherwise
     */
    virtual bool cleanSewage();

    /**
     * @brief Process industrial waste from power generation
     * @return True if waste was successfully processed, false otherwise
     */
    virtual bool cleanWaste();

    /**
     * @brief Get the type of industrial building
     * @return String indicating building type
     */
    virtual string getBuildingType();

    /**
     * @brief Get number of jobs created by the power plant
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
     * @return Power plant name as string
     */
    virtual string getName();

    /**
     * @brief Get power requirement for internal operations
     * @return Power requirement in units
     */
    virtual int getPowerReq();

    /**
     * @brief Get sewage processing cost
     * @return Sewage cost in currency units
     */
    virtual int getSewageCost();

    /**
     * @brief Get water requirement for plant operations
     * @return Water requirement in units
     */
    virtual int getWaterReq();

    /**
     * @brief Perform primary power generation operations
     */
    virtual void operation();

    /**
     * @brief Process maintenance payment for equipment and facilities
     * @return True if maintenance was paid successfully, false otherwise
     */
    virtual bool payMaintenance();

    /**
     * @brief Process power reception for internal operations
     * @return True if power was received successfully, false otherwise
     */
    virtual bool receivePower();

    /**
     * @brief Process water reception for cooling and operations
     * @return True if water was received successfully, false otherwise
     */
    virtual bool receiveWater();

    /**
     * @brief Request current operational state of power plant
     */
    virtual void requestState();

    /**
     * @brief Get industrial waste processing cost
     * @return Waste processing cost in currency units
     */
    int getWasteCost();

    /**
     * @brief Set building operational state
     */
    void setState();

    /**
     * @brief Get total power sales revenue
     * @return Sales revenue as float
     */
    float getSales();

    /**
     * @brief Perform secondary power plant operations
     */
    void operation2();

    /**
     * @brief Get net operational profit
     * @return Profit as float
     */
    float getProfit();
};

#endif
