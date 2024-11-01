#ifndef POWERPLANTBUILDER_H
#define POWERPLANTBUILDER_H

#include "UtilityBuilder.h"
#include "UtilityPowerPlant.h"
#include "HydroFactory.h"
#include "WindFactory.h"
#include "NuclearFactory.h"
#include "CoalFactory.h"

class PowerPlantBuilder : public UtilityBuilder {
public:
	UtilityPowerPlant* getPowerPlant();

	void switchFuel();

	void addCommand(Command* com);

	PowerPlantBuilder(int currentOutput);

	void setMaxWatts(float max);
};

#endif
