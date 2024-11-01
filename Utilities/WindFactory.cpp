#include "WindFactory.h"

EnergySource* WindFactory::createEnergySource(int output) {
	return new WindSource(output);
}
