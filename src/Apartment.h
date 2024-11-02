#include <string>
using namespace std;

#ifndef APARTMENT_H
#define APARTMENT_H

class ResourceMediator;
class Citizen;
#include "ResidentialBuilding.h";

/**
 * @brief A class representing an apartment residential building
 * @details Inherits from ResidentialBuilding and implements residential building operations
 *          for apartment-style housing, including resource management and resident tracking
 */
class Apartment : ResidentialBuilding {
private: 
    /** @brief Pointer to current state of the apartment building */
    State* state;
    
    /** @brief Maximum number of residents that can live in the apartment */
    int capacity;
    
    /** @brief Smart pointer to array of citizens currently residing in the apartment
     *  @note Using smart pointer to prevent memory leaks
     */
    std::unique_ptr<Citizen> listOfCitizens;
    
    /** @brief Power requirement in units per month */
    int powerReq;
    
    /** @brief Water requirement in units per month */
    int waterReq;
    
    /** @brief Monthly cost for maintaining the apartment */
    double maintenanceCost;
    
    /** @brief Cost for sewage processing per month */
    int sewageCost;
    
    /** @brief Amount of waste produced per month */
    int waste;
    
    /** @brief Type identifier for the building */
    string buildingType;
    
    /** @brief Name identifier for the apartment */
    string buildingName;

public: 
    /**
     * @brief Constructor for Apartment
     * @param bName Name of the apartment building
     * @param pReq Power requirement
     * @param wReq Water requirement
     * @param mCost Maintenance cost
     * @param sCost Sewage cost
     * @param waste Waste production
     * @param capacity Maximum number of residents
     */
    Apartment(string bName, int pReq, int wReq, double mCost, int sCost, int waste, int capacity);

    /**
     * @brief Request current state of the apartment building
     */
    void requestState();

    /**
     * @brief Get maximum resident capacity
     * @return Maximum number of residents that can live in the apartment
     */
    int getCapacity();

    /**
     * @brief Get list of current residents
     * @return Smart pointer to array of Citizen objects
     */
    std::unique_ptr<Citizen> getListOfResidents();

    /**
     * @brief Get monthly maintenance cost
     * @return Maintenance cost as double
     */
    double getMaiantenanceCost();

    /**
     * @brief Get power requirement
     * @return Power requirement in units
     */
    int getPowerReq();

    /**
     * @brief Get water requirement
     * @return Water requirement in units
     */
    int getWaterReq();

    /**
     * @brief Get sewage processing cost
     * @return Sewage cost in currency units
     */
    int getSewageCost();

    /**
     * @brief Get waste processing cost
     * @return Waste cost in currency units
     */
    int getWasteCost();

    /**
     * @brief Set building state
     */
    void setState();

    /**
     * @brief Get building name
     * @return Building name as string
     */
    string getName();

    /**
     * @brief Destructor for Apartment class
     * @note Handles cleanup of resources when apartment object is destroyed
     */
    ~Apartment();
};

#endif
