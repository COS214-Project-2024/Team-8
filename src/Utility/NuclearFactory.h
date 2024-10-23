#ifndef NUCLEARFACTORY_H
#define NUCLEARFACTORY_H

#include "EnergyFactory.h"
#include "NuclearSource.h"
class NuclearFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(int output);
};

#endif
