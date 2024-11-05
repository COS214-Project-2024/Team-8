#include "NuclearSource.h"

/**
 * @brief Create a NuclearSource object
 * 
 * @param output The output of the NuclearSource
 */
NuclearSource::NuclearSource(float output) {
	this->energyOutput = output;
}

/**
 * @brief Get the energy output of the NuclearSource
 * 
 * @return float The energy output of the NuclearSource
 */
float NuclearSource::getEnergyOutput() {
	return this->energyOutput;
}

/**
 * @brief Get the fuel type of the NuclearSource
 * 
 * @return std::string The fuel type of the NuclearSource
 */
std::string NuclearSource::getFuelType() {
	return "Nuclear";
}
