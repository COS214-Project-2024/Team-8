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
	SewageSystems(float output);

	std::string getStatus();

	void repareUtility();

	void executeOperation();

	float getOutput();

	void pauseOperation();

	void setmaxWaste(int max);

	void undoChange();

	std::string getUtilityType();

	Utility* clone();

	void repairUtility();
};

#endif
