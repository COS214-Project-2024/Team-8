#include "NuclearFactory.h"

/**
 * @brief Create an EnergySource object of type NuclearSource
 * 
 * @param output The output of the NuclearSource
 * 
 * @return EnergySource* The EnergySource object created
 */
EnergySource* NuclearFactory::createEnergySource(float output) {
	return new NuclearSource(output);
}
