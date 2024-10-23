#include "HydroFactory.h"

#include "HydroSource.h"


EnergySource* HydroFactory::createEnergySource(int output) {
	return new HydroSource(output);
}
