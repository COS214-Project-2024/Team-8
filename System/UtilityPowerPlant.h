#ifndef UTILITYPOWERPLANT_H
#define UTILITYPOWERPLANT_H

#include "Utility.h"
#include "WindFactory.h"
#include "HydroFactory.h"
#include "CoalFactory.h"
#include "NuclearFactory.h"
/**
 * @file UtilityPowerPlant.h
 * 
 * @brief The header file for the UtilityPowerPlant class
 */
class UtilityPowerPlant : public Utility {

private:
	float maximumWatts;
	EnergySource* fuel;

public:
/**
 * @brief Create a UtilityPowerPlant object
 * 
 * @param output The output of the UtilityPowerPlant
 * 
 * The constructor for the UtilityPowerPlant class
 * Also sets the fuel using the switchFuel function
 */
	UtilityPowerPlant(float output);
/**
 * @brief Get the status of the UtilityPowerPlant
 * 
 * @return std::string The status of the UtilityPowerPlant
 */
	std::string getStatus();
/**
 * @brief Repair the UtilityPowerPlant
 * 
 * Repairs the UtilityPowerPlant
 * Also sets the status to operational
 */
	void repairUtility();
/**
 * @brief Execute the operation of the UtilityPowerPlant
 * 
 * Sets the status to operational
 */
	void executeOperation();
/**
 * @brief Get the output of the UtilityPowerPlant
 * 
 * @return float The output of the UtilityPowerPlant
 */
	float getOutput();
/**
 * @brief Set the output of the UtilityPowerPlant
 * 
 * @param Output The output of the UtilityPowerPlant
 * 
 * CHanges the fuel type of the UtilityPowerPlant based on the output
 */
	void setOutput(float Output);
/**
 * @brief Pause the operation of the UtilityPowerPlant
 * 
 * Sets the status to paused
 */
	void pauseOperation();
/**
 * @brief Set the max watts of the UtilityPowerPlant
 * 
 * @param max The max watts of the UtilityPowerPlant
 */
	void setMaxWatts(float max);
/**
 * @brief Set the fuel of the UtilityPowerPlant
 * 
 * @param fuel The fuel of the UtilityPowerPlant
 */
	void setFuel(EnergySource* fuel);
/**
 * @brief Set the fuel of the UtilityPowerPlant
 * 
 * @param fuel The fuel of the UtilityPowerPlant
 */
	std::string getEnergyType();
/**
 * @brief Get the utility type of the UtilityPowerPlant
 * 
 * @return std::string The utility type of the UtilityPowerPlant
 */
	std::string getUtilityType();
/**
 * @brief Switch the fuel of the UtilityPowerPlant
 * 
 * Changes the fuel type of the UtilityPowerPlant based on the current fuel type
 */
	void switchFuel();
/**
 * @brief Clone the UtilityPowerPlant
 * 
 * @return Utility* The cloned UtilityPowerPlant
 */
	Utility* clone();
/**
 * @brief Undo the last change to the UtilityPowerPlant
 * 
 * Undoes the last change to the UtilityPowerPlant
 */
	void undoChange();
/**
 * @brief Get the power from the UtilityPowerPlant
 * 
 * @param sender The sender of the power
 * 
 * @return bool True if the power was received, false otherwise
 */
	bool getPower(Buildings* sender);
/**
 * @brief Add a building to the UtilityPowerPlant
 * 
 * @param building The building to add
 */
	void addBuilding(Buildings* building);
/**
 * @brief Destroy the UtilityPowerPlant object
 * 
 * Destroys the UtilityPowerPlant object
 */
	~UtilityPowerPlant();
};

#endif
