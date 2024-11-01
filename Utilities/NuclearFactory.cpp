#include "NuclearFactory.h"

EnergySource* NuclearFactory::createEnergySource(int output) {
	return new NuclearSource(output);
}
