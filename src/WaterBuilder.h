#ifndef WATERBUILDER_H
#define WATERBUILDER_H

#include "UtilityBuilder.h"
#include "WaterSupply.h"
class WaterBuilder : public UtilityBuilder {
public:
	WaterSupply* getWaterManager();

	void addCommand(Command* com);

	void setMaxGallons(int max);

	WaterBuilder(int curSuplly);

	void undoChange();
};

#endif
