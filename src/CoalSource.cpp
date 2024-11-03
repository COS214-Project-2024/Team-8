#include "CoalSource.h"
/**
 * @brief Create a CoalSource object
 * 
 * @param output The output of the CoalSource
 */
CoalSource::CoalSource(float output) {
	this->energyOutput = output;
}

/**
 * @brief Get the energy output of the CoalSource
 * 
 * @return float The energy output of the CoalSource
 */
float CoalSource::getEnergyOutput() {
	return this->energyOutput;
}

/**
 * @brief Get the fuel type of the CoalSource
 * 
 * @return std::string The fuel type of the CoalSource
 */
std::string CoalSource::getFuelType() {
	return "Coal";
}
