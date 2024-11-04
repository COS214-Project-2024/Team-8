#include "Buildings.h"
#include <string>
using namespace std;

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

/**
 * @class ResidentialBuilding
 * @brief Abstract class representing a residential building, inheriting from Buildings.
 */
class ResidentialBuilding : public Buildings {

protected:
    // Maintenance and resource requirements
    int capacity; ///< Capacity of the building
    int waste; 

    // Mediator and state
    Utility* resources; ///< Mediator for resources
    State* state; ///< Current state of the building

public:
    // Pure virtual functions for building operations
    /**
     * @brief Requests the current state of the building.
     */
    virtual void requestState() = 0;

    /**
     * @brief Cleans the sewage of the building.
     * @return True if the cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage() = 0;

    /**
     * @brief Cleans the waste of the building.
     * @return True if the cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste() = 0;

    /**
     * @brief Gets the type of building.
     * @return Type of the building as a string.
     */
    virtual string getBuildingType() = 0;

    /**
     * @brief Gets the number of jobs created by the building.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated(){return 0;}

    /**
     * @brief Gets the maintenance cost of the building.
     * @return Maintenance cost as a double.
     */
    virtual double getMaintenanceCost() = 0;

    /**
     * @brief Gets the name of the building.
     * @return Name of the building as a string.
     */
    virtual string getName() = 0;

    /**
     * @brief Gets the power requirement of the building.
     * @return Power requirement as an integer.
     */
    virtual int getPowerReq() = 0;

    /**
     * @brief Gets the sewage cost of the building.
     * @return Sewage cost as an integer.
     */
    virtual int getSewageCost() = 0;

    /**
     * @brief Gets the water requirement of the building.
     * @return Water requirement as an integer.
     */
    virtual int getWaterReq() = 0;

    /**
     * @brief Receives power for the building.
     * @return True if power was received successfully, false otherwise.
     */
    virtual bool getPower() = 0;

    /**
     * @brief Receives water for the building.
     * @return True if water was received successfully, false otherwise.
     */
    virtual bool getWater() = 0;

    /**
     * @brief Receives water for the building.
     * @return True if water was received successfully, false otherwise.
     */
    int getCapacity()
    {
        return this->capacity;
    }

    /**
	 * @brief Add a building to the Building
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding() = 0;

    /**
     * @brief sets the state of the building
     */
    virtual void setState(State* newState) = 0;

};

#endif

