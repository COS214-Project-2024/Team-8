#ifndef WASTEBUILDER_H
#define WASTEBUILDER_H

#include "UtilityBuilder.h"
#include "WasteManagement.h"
class WasteBuilder : public UtilityBuilder {
public:
	WasteManagement* getWasteManager();

	WasteBuilder(int curload);

	void addCommand(Command* com);

	void setCapacity(int max);
};

#endif
