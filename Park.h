#include "LandmarkBuilding.h"
#include <string>
using namespace std;

#ifndef PARK_H
#define PARK_H

/**
 * @class Park
 * @brief Represents a park as a type of landmark building.
 */
class Park : public LandmarkBuilding {
    int waste;
public:
    /**
     * @brief Constructor for the Park class.
     * @param bName Name of the park.
     * @param pReq Power requirements.
     * @param wReq Water requirements.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste generated.
     */
    Park(string bName, int pReq, int wReq, double mCost, int sCost, int waste);

    /**
     * @brief Gets the type of the building.
     * @return The building type as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the number of jobs created by the park.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the park.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the park.
     * @return The name of the park as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirements of the park.
     * @return The power requirements as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the park.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the water requirements of the park.
     * @return The water requirements as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Requests the current state of the park.
     */
    virtual void requestState();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);

    /**
     * @brief Gets the waste cost for the park.
     * @return The waste cost as an integer.
     */
    int getWasteCost();

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

