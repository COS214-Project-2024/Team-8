#include "PublicServiceBuilding.h"
#include "State.h"
#include "UnderConstruction.h"
#include <string> 
using namespace std;

#ifndef MEDICALCENTER_H
#define MEDICALCENTER_H

/**
 * @class MedicalCenter
 * @brief Represents a medical center, inheriting from PublicServiceBuilding.
 */
class MedicalCenter : public PublicServiceBuilding {
protected:
    int waste;                    /**< Waste produced by the medical center. */
    int employment;               /**< Number of employees working in the medical center. */
    float healthCoverage;         /**< Health coverage provided by the medical center. */
    int birthRate;                /**< Birth rate supported by the medical center. */
public:
    /**
     * @brief Constructs a MedicalCenter object.
     * @param bName Name of the medical center.
     * @param pReq Power requirement.
     * @param wReq Water requirement.
     * @param mCost Maintenance cost.
     * @param sCost Sewage cost.
     * @param waste Waste produced.
     * @param employment Number of employees.
     * @param hCov Health coverage.
     */
    MedicalCenter(string bName,int pReq, int wReq, double mCost, int sCost, int waste, int employment, float hCov);
/**
     * @brief Gets the type of the building.
     * @return The building type as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the water requirements of the police station.
     * @return The water requirements as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Gets the number of jobs created by the police station.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the police station.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the police station.
     * @return The name of the police station as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirements of the police station.
     * @return The power requirements as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the police station.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the waste cost for the police station.
     * @return The waste cost as an integer.
     */
    virtual int getWasteCost();

    /**
     * @brief Requests the current state of the police station.
     */
    virtual void requestState();

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
    virtual bool getWater() ;

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
     * @brief Gets the health coverage provided by the medical center.
     * @return The health coverage as a float.
     */
    float getHealthCoverage();

    /**
     * @brief Gets the birth rate supported by the medical center.
     * @return The birth rate as an integer.
     */
    int getBirthRate();
};

#endif

