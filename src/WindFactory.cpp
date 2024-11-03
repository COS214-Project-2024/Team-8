#include "WindFactory.h"

/**
 * @brief Create an EnergySource object of type WindSource
 * 
 * @param output The output of the WindSource
 */
EnergySource* WindFactory::createEnergySource(float output) {
	return new WindSource(output);
}