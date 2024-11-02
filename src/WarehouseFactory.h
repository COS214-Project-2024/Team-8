#ifndef WAREHOUSEFACTORY_H
#define WAREHOUSEFACTORY_H

#include "Buildings.h"
#include "IndustrialFactory.h"

class WarehouseFactory : IndustrialFactory {

public:
	Buildings* buildings;
	virtual Buildings* createBuilding();
};

#endif
