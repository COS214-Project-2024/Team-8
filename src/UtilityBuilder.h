#ifndef UTILITYBUILDER_H
#define UTILITYBUILDER_H

#include "WaterSupply.h"
#include "WasteManagement.h"
#include "SewageSystems.h"

#include <iostream>
class UtilityBuilder {
protected:
	Utility* utility;

public:
	virtual WaterSupply* getWaterManager();

	virtual WasteManagement* getWasterManager();

	virtual SewageSystems* getSewageSystem();

	virtual void addCommand(Command* com) = 0;

	virtual void setMaxWaste(int max);

	virtual void setCapacity(int max);

	virtual void setMaxGallons(int max);

	virtual void setMaxWatts(float max);

	virtual void switchFuel();

	UtilityBuilder();

	virtual ~UtilityBuilder();
};

#endif
