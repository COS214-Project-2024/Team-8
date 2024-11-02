#ifndef CULTURALCENTERFACTORY_H
#define CULTURALCENTERFACTORY_H

#include "Buildings.h"
#include "LandmarkFactory.h"

class CulturalCenterFactory : LandmarkFactory {

public:
	Buildings* buildings;

	virtual Buildings* createBuilding();
};

#endif
