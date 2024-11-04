#ifndef SEWAGESYSTEMS_H
#define SEWAGESYSTEMS_H

#include "Utility.h"
/**
 * @file SewageSystems.h
 * 
 * @brief The header file for the SewageSystems class
 */
class SewageSystems : public Utility {
private:
	int maxWaste;
	float blockagepercentage;

public:
/**
 * @brief Create a SewageSystems object
 * 
 * @param output The output of the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 * Command history is used to keep track of the operations done on the SewageSystems
 */
	SewageSystems(float output);
/**
 * @brief Repare the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 * Simulates a repair operation by printing a series of '#' to the console
 */
	std::string getStatus();
/**
 * @brief Execute the operation of the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 */
	void executeOperation();
/**
 * @brief Get the output of the SewageSystems
 * 
 * @return float The output of the SewageSystems
 */
	float getOutput();
/**
 * @brief Pause the operation of the SewageSystems
 * 
 * Sets the status to "Paused" and adds the status to the commandHistory
 */
	void pauseOperation();
/**
 * @brief Set the maximum waste of the SewageSystems
 * 
 * @param max The maximum waste of the SewageSystems
 */
	void setmaxWaste(int max);
/**
 * @brief Undo the last operation done on the SewageSystems
 * 
 * If the last operation was "Operational", the SewageSystems is paused
 * If the last operation was "Paused", the SewageSystems is set to operational
 * If there are no more operations to undo, a message is printed to the console
 */
	void undoChange();
/**
 * @brief Get the type of the SewageSystems
 * 
 * @return std::string The type of the SewageSystems
 */
	std::string getUtilityType();
/**
 * @brief Clone the SewageSystems
 * 
 * @return Utility* The cloned SewageSystems
 */
	Utility* clone();
/**
 * @brief Repare the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 * Simulates a repair operation by printing a series of '#' to the console
 */
	void repairUtility();
/**
 * @brief Set the output of the SewageSystems
 * 
 * @param Output The output of the SewageSystems
 */
	void setOutput(float Output);
/**
 * @brief Add a building to the SewageSystems
 * 
 * @param building The building to add to the SewageSystems
 */
	void addBuilding(Buildings* building);
/**
 * @brief Clean the sewage
 * 
 * @param sender The building that sent the sewage
 * 
 * @return bool True if the sewage was cleaned, false otherwise
 */
	bool cleanSewage(Buildings* sender);
};

#endif
