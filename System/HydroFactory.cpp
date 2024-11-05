#include "HydroFactory.h"

/**
 * @brief Create an EnergySource object of type HydroSource
 * 
 * @param output The output of the HydroSource
 * 
 * @return EnergySource* The EnergySource object created
 */
EnergySource* HydroFactory::createEnergySource(float output) {
	return new HydroSource(output);
}
