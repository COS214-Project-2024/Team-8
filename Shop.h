#include "CommercialBuilding.h"
#include <string> 
using namespace std;

#ifndef SHOP_H
#define SHOP_H

/**
 * @class Shop
 * @brief Class representing a shop, inheriting from CommercialBuilding.
 */
class Shop : public CommercialBuilding {

protected:
    // Basic building details
    string buildingName; ///< Name of the shop
    string buildingType; ///< Type of the shop
    Citizen* listOfCitizens; ///< List of citizens associated with the shop

    // Resource and cost requirements
    double maintenanceCost; ///< Cost required for maintenance
    int powerReq; ///< Power requirement for the shop
    int waterReq; ///< Water requirement for the shop
    int sewageCost; ///< Sewage cost for the shop
    int waste; ///< Waste generated by the shop
    ResourceMediator* resources; ///< Mediator for resources

    // Business metrics
    float sales; ///< Total sales made by the shop
    float profit; ///< Total profit made by the shop
    int employment; ///< Employment generated by the shop

    // Current building state
    State* state; ///< Current state of the shop

public:
    /**
     * @brief Constructs a Shop object.
     * @param bName Name of the shop.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     * @param sales Total sales made by the shop.
     * @param profit Total profit made by the shop.
     * @param emp Employment opportunities created by the shop.
     */
    Shop(string bName, int pReq, int wReq, double mCost, int sCost, int waste, float sales, float profit, int emp);

    /**
     * @brief Cleans the sewage of the shop.
     * @return True if the cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the shop.
     * @return True if the cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of building.
     * @return Type of the building as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the shop.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the shop.
     * @return Maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the shop.
     * @return Name of the shop as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the shop.
     * @return Power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the shop.
     * @return Sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the shop.
     * @return Water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Performs operations associated with the shop.
     */
    virtual void operation();

    /**
     * @brief Pays for the maintenance of the shop.
     * @return True if payment was successful, false otherwise.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the shop.
     * @return True if power was received successfully, false otherwise.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the shop.
     * @return True if water was received successfully, false otherwise.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the shop.
     */
    virtual void requestState();

    /**
     * @brief Sets the state of the shop.
     */
    void setState();

    /**
     * @brief Gets the waste cost associated with the shop.
     * @return Waste cost as an integer.
     */
    int getWasteCost();

    // Additional functions

    /**
     * @brief Gets the total sales made by the shop.
     * @return Total sales as a float.
     */
    float getSales();

    /**
     * @brief Gets the total profit made by the shop.
     * @return Total profit as a float.
     */
    float getProfit();

    /**
     * @brief Pays a citizen associated with the shop.
     * @return The amount paid to the citizen as an integer.
     */
    int payCitizen();
};

#endif