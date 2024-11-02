#ifndef ENERGYFACTORY_H
#define ENERGYFACTORY_H

#include "EnergySource.h"
class EnergyFactory {
public:
	virtual EnergySource* createEnergySource(int output) = 0;
};

#endif
