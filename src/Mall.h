#include "CommercialBuilding.h"
#include <string> 
using namespace std;

#ifndef MALL_H
#define MALL_H

/**
 * @class Mall
 * @brief Represents a mall, inheriting from CommercialBuilding.
 */
class Mall : public CommercialBuilding {

protected:
    string buildingName;          /**< Name of the mall. */
    string buildingType;          /**< Type of the mall. */
    Citizen* listOfCitizens;      /**< List of citizens associated with the mall. */

    double maintenanceCost;       /**< Maintenance cost for the mall. */
    int powerReq;                 /**< Power requirement of the mall. */
    int waterReq;                 /**< Water requirement of the mall. */
    int sewageCost;               /**< Sewage cost for the mall. */
    int income;                   /**< Income generated by the mall. */
    int waste;                    /**< Waste produced by the mall. */
    ResourceMediator* resources;  /**< Mediator for managing resources. */

    float sales;                  /**< Total sales made by the mall. */
    float profit;                 /**< Profit made by the mall. */
    int employment;               /**< Number of employees working in the mall. */

    State* state;                 /**< Current state of the mall. */

public:
    /**
     * @brief Constructs a Mall object.
     * @param bName Name of the mall.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     * @param sales Total sales.
     * @param profit Total profit.
     * @param emp Number of employees.
     */
    Mall(string bName,int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);

    /**
     * @brief Cleans the sewage of the mall.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the mall.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the mall.
     * @return The type of the mall as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the mall.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the mall.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the mall.
     * @return The name of the mall as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the mall.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the mall.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the mall.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Performs the operation of the mall.
     */
    virtual void operation();

    /**
     * @brief Pays the maintenance cost for the mall.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the mall.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the mall.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the mall.
     */
    virtual void requestState();

    /**
     * @brief Sets the state of the mall.
     */
    void setState();

    /**
     * @brief Gets the income generated by the mall.
     * @return The income as an integer.
     */
    int getIncome();

    /**
     * @brief Gets the waste cost for the mall.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

    /**
     * @brief Gets the total sales of the mall.
     * @return The sales as a float.
     */
    float getSales();

    /**
     * @brief Gets the total profit of the mall.
     * @return The profit as a float.
     */
    float getProfit();

    /**
     * @brief Pays a citizen from the mall's profits.
     * @return The payment amount as an integer.
     */
    int payCitizen();
};

#endif

