#ifndef UTILITYPOWERPLANT_H
#define UTILITYPOWERPLANT_H

#ifndef UTILITYPOWERPLANT_H
#define UTILITYPOWERPLANT_H

#include "Utility.h"
#include "WindFactory.h"
#include "HydroFactory.h"
#include "CoalFactory.h"
#include "NuclearFactory.h"
/**
 * @file UtilityPowerPlant.h
 * 
 * @brief The header file for the UtilityPowerPlant class
 */
class UtilityPowerPlant : public Utility {

private:
	float maximumWatts;
	EnergySource* fuel;

public:
	UtilityPowerPlant(float output);

	std::string getStatus();

	void repairUtility();

	void executeOperation();

	float getOutput();

	void setOutput(float Output);

	void pauseOperation();
	void pauseOperation();

	void setMaxWatts(float max);

	void setFuel(EnergySource* fuel);
	void setFuel(EnergySource* fuel);

	std::string getEnergyType();

	std::string getUtilityType();

	void switchFuel();

	Utility* clone();

	void undoChange();
};

#endif
