#include <exception>
#include <string>
using namespace std;

#ifndef __UtilityPowerPlant_h__
#define __UtilityPowerPlant_h__

// #include "Command.h"
// #include "EnergySource.h"
#include "Utility.h"

class Command;
class EnergySource;
// class Utility;
class UtilityPowerPlant;

class UtilityPowerPlant: public Utility
{
	private: float _maximumWatts;
	private: int _currentOutput;
	private: EnergySourcel* _fuel;

	public: UtilityPowerPlant(int aOutput);

	public: string getEnergyType();

	public: void executeOperation();

	public: void repareUtility();

	public: string getStatus();

	public: void pauseOperation();

	public: void addCommand(Command* aCom);

	public: void setMaxWatts(float aMax);

	public: void setFuel(EnergySource* aFuel);

	public: virtual void repairUtility();
};

#endif
