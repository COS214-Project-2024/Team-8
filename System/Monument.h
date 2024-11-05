#include "LandmarkBuilding.h"
#include <string>
using namespace std;

#ifndef MONUMENT_H
#define MONUMENT_H

/**
 * @class Monument
 * @brief Represents a monument, inheriting from LandmarkBuilding.
 */
class Monument : public LandmarkBuilding {
protected:
    int waste;

public:
    /**
     * @brief Constructs a Monument object.
     * @param bName Name of the monument.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     */
    Monument(string bName,int pReq, int wReq, double mCost, int sCost, int waste);

    /**
     * @brief Gets the type of the monument.
     * @return The type of the monument as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the maintenance cost of the monument.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the monument.
     * @return The name of the monument as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the monument.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the monument.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirement of the monument.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();


    /**
     * @brief Requests the current state of the monument.
     */
    virtual void requestState();

    /**
     * @brief Gets the waste cost for the monument.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);

     /**
	 * @brief Add a building to the Utility resource
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding();

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
};

#endif

