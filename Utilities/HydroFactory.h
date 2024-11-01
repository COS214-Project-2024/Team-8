#ifndef HYDROFACTORY_H
#define HYDROFACTORY_H

#include "EnergyFactory.h"
#include "HydroFactory.h"
class HydroFactory : public EnergyFactory {
public:
	EnergySource* createEnergySource(int output);
};

#endif
