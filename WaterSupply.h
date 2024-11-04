#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"
#include <iostream>
#include "Command.h"
/**
 * @file WaterSupply.h
 * 
 * @brief The header file for the WaterSupply class
 */
class WaterSupply : public Utility {

private:
	int maxGallons;
	float puritypercentage;

public:
/**
 * @brief Create a WaterSupply object
 * 
 * @param curSupply The current supply of the WaterSupply
 */
	WaterSupply(float curSupply);

	void addCommand(Command* com);
/**
 * @brief returns the status of the WaterSupply
 * 
 * @return std::string The status of the WaterSupply
 */
	std::string getStatus();
/**
 * @brief Repairs the WaterSupply
 * 
 * Repairs the WaterSupply
 * Also sets the status to operational
 */
	void repairUtility();
/**
 * @brief Pauses the operation of the WaterSupply
 * 
 * Sets the status to paused
 */
	void pauseOperation();
/**
 * @brief Executes the operation of the WaterSupply
 * 
 * Sets the status to operational
 */
	void executeOperation();
/**
 * @brief Sets the max gallons of the WaterSupply
 * 
 * @param max The max gallons of the WaterSupply
 */
	void setMaxGallons(float max);
/**
 * @brief Gets the output of the WaterSupply
 * 
 * @return float The output of the WaterSupply
 */
	float getOutput();
/**
 * @brief Undoes the last change to the WaterSupply
 * 
 * Undoes the last change to the WaterSupply
 * Also sets the status to paused
 */
	void undoChange();
/**
 * @brief Clones the WaterSupply
 * 
 * @return Utility* The cloned WaterSupply
 */
	Utility* clone();
	/**
	 * @brief Get the utility type of the WaterSupply
	 * 
	 * @return std::string The utility type of the WaterSupply
	 */
	std::string getUtilityType();
	/**
	 * @brief Add a building to the WaterSupply
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	void addBuilding(Buildings* building);
	/**
	 * @brief Get water from the WaterSupply
	 * 
	 * @param sender The building requesting water
	 * 
	 * @return bool True if water was sent, false otherwise
	 */
	bool getWater(Buildings* sender);
};

#endif
