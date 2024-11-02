#include "CommercialBuilding.h"
#include <string> 
using namespace std;

#ifndef SHOP_H
#define SHOP_H

/**
 * @brief A class representing a commercial shop building
 * @details Inherits from CommercialBuilding and implements commercial operations
 *          including sales, profit tracking, and resource management
 */
class Shop : CommercialBuilding {
protected:
    /** @brief Name identifier for the shop */
    string buildingName;
    
    /** @brief Type identifier for the building */
    string buildingType;
    
    /** @brief Pointer to array of citizens working in or associated with the shop */
    Citizen* listOfCitizens;
    
    /** @brief Monthly cost for maintaining the shop */
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
    
    /** @brief Total sales revenue for the shop */
    float sales;
    
    /** @brief Net profit after expenses */
    float profit;
    
    /** @brief Number of employees working in the shop */
    int employment;
    
    /** @brief Pointer to current state of the building */
    State* state;

public:
    /**
     * @brief Constructor for Shop
     * @param bName Name of the shop
     * @param pReq Power requirement
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Waste production
     * @param sales Initial sales value
     * @param profit Initial profit value
     * @param emp Number of employees
     */
    Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);

    /**
     * @brief Process sewage for the shop
     * @return True if sewage was successfully processed, false otherwise
     */
    virtual bool cleanSewage();

    /**
     * @brief Process waste for the shop
     * @return True if waste was successfully processed, false otherwise
     */
    virtual bool cleanWaste();

    /**
     * @brief Get the type of building
     * @return String indicating building type
     */
    virtual string getBuildingType();

    /**
     * @brief Get number of jobs created by this shop
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
     * @brief Get water cost
     * @return Water cost in currency units
     */
    virtual int getWaterCost();

    /**
     * @brief Perform primary building operations
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
     * @brief Get total sales revenue
     * @return Sales revenue as float
     */
    float getSales();

    /**
     * @brief Perform secondary building operations
     */
    void operation2();

    /**
     * @brief Get net profit
     * @return Profit as float
     */
    float getProfit();
};

#endif
