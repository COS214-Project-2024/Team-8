#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "UtilityManager.h"
#include "CitySector.h"

class EnergySource;
class Utility
{
protected:
	std::string status;
	//Buildings* buildinglist;
	UtilityManager* manager;

public:
	virtual std::string getStatus();
	virtual void setFuel(EnergySource* fuel);
	virtual void executeOperation() = 0;
	virtual void setmaxWaste(int max);
	virtual void repairUtility() = 0;
	virtual std::string getEnergyType();
	virtual void setProcessCapacity(int pro);
	virtual int getCurrentSupply();
	virtual int getCurrentLoad();
	virtual void undoChange() = 0;
	virtual void setMaxWatts(float max);
	virtual int getCurrentOutput();
	virtual void setMaxGallons(float max);
	virtual void pauseOperation() = 0;
	virtual void addCommand(Command* com) = 0;
	virtual float getMaxWatts();
	virtual std::string getUtilityType() = 0;
	virtual ~Utility();
};

#endif
