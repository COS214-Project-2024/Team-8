#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"
#include <iostream>
#include "Command.h"

class WaterSupply : public Utility {
private:
	int maxGallons;
	float puritypercentage;
	int currentSupply;

public:
	WaterSupply(int curSupply);

	std::string getStatus();

	void repairUtility();

	void executeOperation();

	int getCurrentSupply();

	void pauseOperation();

	void addCommand(Command* com);

	void setMaxGallons(float max);

	std::string getUtilityType();

	void undoChange();
};

#endif
