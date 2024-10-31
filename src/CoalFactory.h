#ifndef COALFACTORY_H
#define COALFACTORY_H

#include "EnergyFactory.h"
#include "CoalSource.h"
class CoalFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(int output);
};

#endif
