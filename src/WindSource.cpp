#include "WindSource.h"

/**
 * @brief Create a WindSource object
 * 
 * @param output The output of the WindSource
 */
WindSource::WindSource(float output) {
	this->energyOutput = output;
}

/**
 * @brief Get the energy output of the WindSource
 * 
 * @return float The energy output of the WindSource
 */
float WindSource::getEnergyOutput() {
	return energyOutput;
}

/**
 * @brief Get the fuel type of the WindSource
 * 
 * @return std::string The fuel type of the WindSource
 */
std::string WindSource::getFuelType() {
	return "Wind";
}