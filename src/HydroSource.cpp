#include "HydroSource.h"

/**
 * @brief Create a HydroSource object
 * 
 * @param output The output of the HydroSource
 */
HydroSource::HydroSource(float output) {
	this->energyOutput = output;
}

/**
 * @brief Get the energy output of the HydroSource
 * 
 * @return float The energy output of the HydroSource
 */
float HydroSource::getEnergyOutput() {
	return this->energyOutput;
}

/**
 * @brief Get the fuel type of the HydroSource
 * 
 * @return std::string The fuel type of the HydroSource
 */
std::string HydroSource::getFuelType() {
	return "Hydro";
}
