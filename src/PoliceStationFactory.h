#ifndef POLICESTATIONFACTORY_H
#define POLICESTATIONFACTORY_H

#include "Buildings.h"
#include "PublicServiceFactory.h"
class PoliceStationFactory : PublicServiceFactory {

public:
	Buildings* buildings;
	virtual Buildings* createBuilding();
};

#endif
