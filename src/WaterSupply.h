#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

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
	WaterSupply(float curSupply);

	std::string getStatus();

	void repairUtility();

	void pauseOperation();

	void executeOperation();

	void setMaxGallons(float max);

	float getOutput();

	void undoChange();

	Utility* clone();

	std::string getUtilityType();
};

#endif
