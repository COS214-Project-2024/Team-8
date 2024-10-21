#include <exception>
using namespace std;

#ifndef __PowerPlantBuilder_h__
#define __PowerPlantBuilder_h__

// #include "EnergyFactory.h"
// #include "PowerPlant.h"
// #include "Command.h"
#include "UtilityBuilder.h"

class EnergyFactory;
class PowerPlant;
class Command;
// class UtilityBuilder;
class PowerPlantBuilder;

class PowerPlantBuilder: public UtilityBuilder
{
	public: EnergyFactory* _unnamed_EnergyFactory_;

	public: PowerPlant* getPowerPlant();

	public: void switchFuel();

	public: void addCommand(Command* aCom);

	public: PowerPlantBuilder(int aCurrentOutput);

	public: void setMaxWatts(float aMax);
};

#endif
