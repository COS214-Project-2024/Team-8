#ifndef MONUMENTFACTORY_H
#define MONUMENTFACTORY_H

#include "Buildings.h"
#include "LandmarkFactory.h"

class MonumentFactory : LandmarkFactory {

public:
	Buildings* buildings;
	virtual Buildings* createBuilding() = 0;
};

#endif
