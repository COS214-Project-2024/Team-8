#ifndef SEWAGESYSTEMS_H
#define SEWAGESYSTEMS_H

#include "Utility.h"
class SewageSystems : public Utility {
private:
	int maxWaste;
	float blockagepercentage;
	int currentload;

public:
	SewageSystems(int curloat);

	std::string getStatus();

	void repairUtility();

	void executeOperation();

	int getCurrentLoad();

	void pauseOperation();

	void addCommand(Command* com);

	void setmaxWaste(int max);

	std::string getUtilityType();

	void undoChange();
};

#endif
