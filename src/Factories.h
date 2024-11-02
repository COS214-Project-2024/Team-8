#include "IndustrialBuilding.h"
#include <string>
using namespace std;

#ifndef FACTORIES_H
#define FACTORIES_H

/**
 * @brief A class representing industrial factory buildings
 * @details Inherits from IndustrialBuilding and implements manufacturing operations,
 *          including production management, resource utilization, and industrial waste handling
 */
class Factories : IndustrialBuilding {
protected:
    /** @brief Name identifier for the factory */
    string buildingName;
    
    /** @brief Type identifier for the building */
    string buildingType;
    
    /** @brief Pointer to array of factory workers */
    Citizen* listOfCitizens;
    
    /** @brief Monthly cost for maintaining factory equipment and facilities */
    double maintenanceCost;
    
    /** @brief Power requirement for manufacturing operations */
    int powerReq;
    
    /** @brief Water requirement for industrial processes */
    int waterReq;
    
    /** @brief Amount of industrial waste produced from manufacturing */
    int waste;
    
    /** @brief Cost for industrial sewage processing per month */
    int sewageCost;
    
    /** @brief Pointer to resource mediator handling resource distribution */
    ResourceMediator* resources;
    
    /** @brief Total revenue from manufactured goods */
    float sales;
    
    /** @brief Net profit after production costs */
    float profit;
    
    /** @brief Number of workers employed in the factory */
    int employment;
    
    /** @brief Pointer to current operational state */
    State* state;

public:
    /**
     * @brief Constructor for Factories
     * @param bName Name of the factory
     * @param pReq Power requirement for manufacturing
     * @param wReq Water requirement for industrial processes
     * @param mCost Maintenance cost
     * @param sCost Sewage processing cost
     * @param waste Industrial waste production rate
     * @param employment Number of required workers
     */
    Factories(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int employment);

    /**
     * @brief Process industrial sewage from manufacturing
     * @return True if sewage was successfully processed, false otherwise
     */
    virtual bool cleanSewage();

    /**
     * @brief Process industrial waste from production
     * @return True if waste was successfully processed, false otherwise
     */
    virtual bool cleanWaste();

    /**
     * @brief Get the type of industrial building
     * @return String indicating factory type
     */
    virtual string getBuildingType();

    /**
     * @brief Get number of manufacturing jobs created
     * @return Number of jobs created
     */
    virtual int getJobsCreated();

    /**
     * @brief Get monthly maintenance cost for equipment
     * @return Maintenance cost as double
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Get factory name
     * @return Factory name as string
     */
    virtual string getName();

    /**
     * @brief Get power requirement for manufacturing
     * @return Power requirement in units
     */
    virtual int getPowerReq();

    /**
     * @brief Get industrial sewage processing cost
     * @return Sewage cost in currency units
     */
    virtual int getSewageCost();

    /**
     * @brief Get water cost for industrial processes
     * @return Water cost in currency units
     */
    virtual int getWaterCost();

    /**
     * @brief Perform primary manufacturing operations
     */
    virtual void operation();

    /**
     * @brief Process equipment maintenance payment
     * @return True if maintenance was paid successfully, false otherwise
     */
    virtual bool payMaintenance();

    /**
     * @brief Process power reception for manufacturing
     * @return True if power was received successfully, false otherwise
     */
    virtual bool receivePower();

    /**
     * @brief Process water reception for industrial use
     * @return True if water was received successfully, false otherwise
     */
    virtual bool receiveWater();

    /**
     * @brief Request current manufacturing state
     */
    virtual void requestState();

    /**
     * @brief Get industrial waste processing cost
     * @return Waste processing cost in currency units
     */
    int getWasteCost();

    /**
     * @brief Set factory operational state
     */
    void setState();

    /**
     * @brief Get total manufacturing sales revenue
     * @return Sales revenue as float
     */
    float getSales();

    /**
     * @brief Perform secondary factory operations
     */
    void operation2();

    /**
     * @brief Get net manufacturing profit
     * @return Profit as float
     */
    float getProfit();
};

#endif
