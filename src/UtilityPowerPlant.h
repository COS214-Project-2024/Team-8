#ifndef UTILITYPOWERPLANT_H
#define UTILITYPOWERPLANT_H

#include "Utility.h"
#include "EnergySource.h"
class UtilityPowerPlant : public Utility {
private:
	float maximumWatts;
	int currentOutput;
	EnergySource* fuel = nullptr;

public:
	UtilityPowerPlant(int output);

	std::string getEnergyType();

	void executeOperation();

	void repairUtility();

	std::string getStatus();

	void pauseOperation();

	void addCommand(Command* com);

	void setMaxWatts(float max);

	void setFuel(EnergySource* fuel);

	float getMaxWatts();

	int getCurrentOutput();

	std::string getUtilityType();

	void undoChange();
};

#endif
