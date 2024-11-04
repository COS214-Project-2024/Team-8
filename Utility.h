#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "Utility.h"
#include "EnergySource.h"
#include "Buildings.h"
/**
 * @file Utility.h
 * 
 * @brief The header file for the Utility class, interface for the utilities
 */
class Utility {
protected:
	std::string status;
	std::vector<std::string> commandHistory;
	std::vector<Buildings*> buildings;
	float Output;

public:
	virtual std::string getStatus() = 0;

	virtual void executeOperation() = 0;

	virtual void repairUtility() = 0;

	virtual void undoChange() = 0;
/**
 * @brief return the output of the Utility
 * 
 * @return float The output of the Utility
 */
	virtual float getOutput();

	virtual void pauseOperation() = 0;
/**
 * @brief Set the max watts of the Utility
 * 
 * @throw NOT A MEMBER OF SAID CLASS
 * 
 * This function only works for the PowerPlant class
 */
	virtual std::string getEnergyType();
/**
 * @brief Set the output of the Utility
 * 
 * @param Output The output of the Utility
 * 
 */
	virtual void setOutput(float Output);

	virtual std::string getUtilityType() = 0;

	virtual Utility* clone() = 0;
/**
 * @brief Set the max watts of the Utility
 * 
 * @param max The max watts of the Utility
 */
	virtual void setMaxWatts(float max);

	virtual void setFuel(EnergySource* fuel);
/**
 * @brief Set the max waste of the Utility
 * 
 * @param max The max waste of the Utility
 */
	virtual void setmaxWaste(int max);
/**
 * @brief Set the fuel of the Utility
 * 
 */
	virtual void switchFuel();
/**
 * @brief Set the max gallons of the Utility
 * 
 * @param max The max gallons of the Utility
 */
	virtual void setMaxGallons(float max);
/**
 * @brief Set the process capacity of the Utility
 * 
 * @param pro The process capacity of the Utility
 */
	virtual void setProcessCapacity(int pro);

	virtual bool getPower(Buildings* sender);
/**
	 * @brief Get water from the WaterSupply
	 * 
	 * @param sender The building requesting water
	 * 
	 * @return bool True if water was sent, false otherwise
	 */
	virtual bool getWater(Buildings* sender);
/**
 * @brief Clean Building that is registered/exists in the Waste Management vector object
 * 
 * @param sender 
 * @return true 
 * @return false 
 */
	virtual bool cleanWaste(Buildings* sender);
/**
 * @brief Clean the sewage
 * 
 * @param sender The building that sent the sewage
 * 
 * @return bool True if the sewage was cleaned, false otherwise
 */
	virtual bool cleanSewage(Buildings* sender);
/**
	 * @brief Add a building to the WaterSupply
	 * 
	 * @param building The building to add to the WaterSupply
	 */
	virtual void addBuilding(Buildings* building) = 0;
/**
 * @brief Destructor for the Utility object
 * Virtual destructor of the Utlity object
 */
	virtual ~Utility() {};
};

#endif
