#include "PublicServiceBuilding.h"
#include <string> 
using namespace std;

#ifndef MEDICALCENTER_H
#define MEDICALCENTER_H

/**
 * @class MedicalCenter
 * @brief Represents a medical center, inheriting from PublicServiceBuilding.
 */
class MedicalCenter : public PublicServiceBuilding {

    /// Building details
    string buildingName;          /**< Name of the medical center. */
    string buildingType;          /**< Type of the medical center. */
    Citizen* listOfCitizens;      /**< List of citizens associated with the medical center. */

    // Resource and maintenance requirements
    double maintenanceCost;       /**< Maintenance cost for the medical center. */
    int powerReq;                 /**< Power requirement of the medical center. */
    int waterReq;                 /**< Water requirement of the medical center. */
    int sewageCost;               /**< Sewage cost for the medical center. */
    int waste;                    /**< Waste produced by the medical center. */
    int employment;               /**< Number of employees working in the medical center. */
    float healthCoverage;         /**< Health coverage provided by the medical center. */
    int birthRate;                /**< Birth rate supported by the medical center. */

    // Resource mediator and state
    ResourceMediator* resources;  /**< Mediator for managing resources. */
    State* state;                 /**< Current state of the medical center. */

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
     * @brief Cleans the sewage of the medical center.
     * @return true if sewage cleaning was successful, false otherwise.
     */
    virtual bool cleanSewage();

    /**
     * @brief Cleans the waste of the medical center.
     * @return true if waste cleaning was successful, false otherwise.
     */
    virtual bool cleanWaste();

    /**
     * @brief Gets the type of the medical center.
     * @return The type of the medical center as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Gets the water requirement of the medical center.
     * @return The water requirement as an integer.
     */
    virtual int getWaterReq();

    /**
     * @brief Gets the number of jobs created by the medical center.
     * @return The number of jobs as an integer.
     */
    virtual int getJobsCreated();

    /**
     * @brief Gets the maintenance cost of the medical center.
     * @return The maintenance cost as a double.
     */
    virtual double getMaintenanceCost();

    /**
     * @brief Gets the name of the medical center.
     * @return The name of the medical center as a string.
     */
    virtual string getName();

    /**
     * @brief Gets the power requirement of the medical center.
     * @return The power requirement as an integer.
     */
    virtual int getPowerReq();

    /**
     * @brief Gets the sewage cost of the medical center.
     * @return The sewage cost as an integer.
     */
    virtual int getSewageCost();

    /**
     * @brief Gets the waste cost for the medical center.
     * @return The waste cost as an integer.
     */
    virtual int getWasteCost();

    /**
     * @brief Pays the maintenance cost for the medical center.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool payMaintenance();

    /**
     * @brief Receives power for the medical center.
     * @return true if power was received successfully, false otherwise.
     */
    virtual bool receivePower();

    /**
     * @brief Receives water for the medical center.
     * @return true if water was received successfully, false otherwise.
     */
    virtual bool receiveWater();

    /**
     * @brief Requests the current state of the medical center.
     */
    virtual void requestState();

    /**
     * @brief Gets the health coverage provided by the medical center.
     * @return The health coverage as a float.
     */
    float getHealthCoverage();

    /**
     * @brief sets the state of the building
     */
    void setState(State* newState);

    /**
     * @brief Gets the birth rate supported by the medical center.
     * @return The birth rate as an integer.
     */
    int getBirthRate();
};

#endif

