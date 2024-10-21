#include <exception>
using namespace std;

#ifndef __EnergyFactory_h__
#define __EnergyFactory_h__

// #include "PowerPlantBuilder.h"
// #include "EnergySource.h"

class PowerPlantBuilder;
class EnergySource;
class EnergyFactory;

__abstract class EnergyFactory
{
	public: PowerPlantBuilder* _unnamed_PowerPlantBuilder_;

	protected: virtual EnergySource* createEnergySource(int aI) = 0;
};

#endif
