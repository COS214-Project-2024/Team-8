#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "Utility.h"
#include "EnergySource.h"
/**
 * @file Utility.h
 * 
 * @brief The header file for the Utility class, interface for the utilities
 */
class Utility {
protected:
	std::string status;
	std::vector<std::string> commandHistory;
	float Output;

public:
	virtual std::string getStatus() = 0;

	virtual void executeOperation() = 0;

	virtual void repairUtility() = 0;

	virtual void undoChange() = 0;

	virtual float getOutput();

	virtual void pauseOperation();

	virtual std::string getEnergyType();

	virtual void setOutput(float Output);

	virtual std::string getUtilityType() = 0;

	virtual Utility* clone() = 0;

	virtual void setMaxWatts(float max);

	virtual void setFuel(EnergySource* fuel);

	virtual void setmaxWaste(int max);

	virtual void switchFuel();

	virtual void setMaxGallons(float max);
};

#endif
