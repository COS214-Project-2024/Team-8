#include "CoalFactory.h"

/**
 * @brief Create an EnergySource object of type CoalSource
 * 
 * @param output The output of the CoalSource
 */
EnergySource* CoalFactory::createEnergySource(float output) {
	return new CoalSource(output);
}
