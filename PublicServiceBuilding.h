#include "Buildings.h"
#include <string>
using namespace std;

#ifndef PUBLICSERVICEBUILDING_H
#define PUBLICSERVICEBUILDING_H

/**
 * @class PublicServiceBuilding
 * @brief Abstract class representing a public service building, inheriting from Buildings.
 */
class PublicServiceBuilding : public Buildings {
protected:
    int waste;

public:
    // Pure virtual functions for building operations
    
    /**
     * @brief Gets the type of building.
     * @return Type of the building as a string.
     */
    virtual string getBuildingType() = 0;
    
    /**
     * @brief Gets the water requirement of the building.
     * @return Water requirement as an integer.
     */
    virtual int getWaterReq() = 0;
    
    /**
     * @brief Gets the number of jobs created by the building.
     * @return Number of jobs created.
     */
    virtual int getJobsCreated() = 0;
    
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
     * @brief Gets the security coverage provided by the police station.
     * @return The security coverage as a float.
     */
    float getEducationalCoverage(){return 0;}

    /**
	 * @brief Add a building to the Utility resource
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding() = 0;

    /**
     * @brief Receives power for the building.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool getPower() = 0;

    /**
     * @brief Receives water for the building.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool getWater() = 0;

    /**
     * @brief Cleans the waste of the building.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste() = 0;

    /**
     * @brief Cleans the sewage of the building.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage() = 0;
    
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
     * @brief Requests the current state of the building.
     */
    virtual void requestState() = 0;

    /**
     * @brief sets the state of the building
     */
    virtual void setState(State* newState) = 0;
    
    /**
     * @brief Gets the waste cost of the building.
     * @return Waste cost as an integer.
     */
    virtual int getWasteCost();

    /**
     * @brief Gets the security coverage provided by the police station.
     * @return The security coverage as a float.
     */
    virtual float getSecurityCoverage(){return 0;}

     /**
     * @brief Gets the health coverage provided by the medical center.
     * @return The health coverage as a float.
     */
    virtual float getHealthCoverage(){return 0;}
};

#endif

