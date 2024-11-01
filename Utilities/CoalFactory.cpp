#include "CoalFactory.h"

EnergySource* CoalFactory::createEnergySource(int output) {
	return new CoalSource(output);
}
