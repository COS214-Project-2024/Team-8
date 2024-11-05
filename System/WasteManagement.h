#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"
/**
 * @file WasteManagement.h
 * 
 * @brief The header file for the WasteManagement class
 */
class WasteManagement : public Utility {

private:
	int processCapacity;
	float recycledperc;

public:
/**
 * @brief 
 * 
 *
 * 
 * @param output The output of the WasteManagement
 * 
 * The constructor for the WasteManagement class
 */
	WasteManagement(float output);
/**
 * @brief Get the status of the WasteManagement
 * 
 * @return std::string The status of the WasteManagement
 */
	std::string getStatus();
/**
 * @brief Repair the WasteManagement
 * 
 * Repairs the WasteManagement
 * Also sets the status to operational
 */
	void repairUtility();
/**
 * @brief Execute the operation of the WasteManagement
 * 
 * Sets the status to operational
 */
	void executeOperation();
/**
 * @brief Get the output of the WasteManagement
 * 
 * @return float The output of the WasteManagement
 */
	float getOutput();
/**
 * @brief Pause the operation of the WasteManagement
 * 
 * Sets the status to paused
 */
	void pauseOperation();
/**
 * @brief Get the utility type of the WasteManagement
 * 
 * @return std::string The utility type of the WasteManagement
 */
	std::string getUtilityType();
/**
 * @brief Clone the WasteManagement
 * 
 * @return Utility* The cloned WasteManagement
 */
	Utility* clone();
/**
 * @brief Set the process capacity of the WasteManagement
 * 
 * @param pro The process capacity of the WasteManagement
 */
	void setProcessCapacity(int pro);
/**
 * @brief Undo the last change to the WasteManagement
 * 
 * Undoes the last change to the WasteManagement
 */
	void undoChange();
/**
 * @brief Add a building to the WasteManagement
 * 
 * @param building The building to add
 */
	void addBuilding(Buildings* building);
/**
 * @brief Clean Building that is registered/exists in the Waste Management vector object
 * 
 * @param sender 
 * @return true 
 * @return false 
 */
	bool cleanWaste(Buildings* sender);
};

#endif
