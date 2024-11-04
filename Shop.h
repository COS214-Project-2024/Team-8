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
     * @brief Requests the current state of the shop.
     */
    virtual void requestState();

   /**
     * @brief sets the state of the building
     */
    void setState(State* newState);

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

     /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual int getCommercialIncome();

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual double getBalance();

    /**
     * @brief gets the current income of a commercial building
     * @return the income as an integer
     */
    virtual void setBalance(double b);

    /**
     * @brief Receives power for the building.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool getPower();

    /**
     * @brief Receives water for the building.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool getWater();

    /**
     * @brief Cleans the waste of the building.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Cleans the sewage of the building.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
	 * @brief Add a building to the Utility resource
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding();
};

#endif
