#ifndef WINDFACTORY_H
#define WINDFACTORY_H

#include "EnergyFactory.h"
#include "WindSource.h"
class WindFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(int output);
};

#endif
