#include "HydroSource.h"

HydroSource::HydroSource(int output) {
	this->energyOutput = output;
}

float HydroSource::getEnergyOutput() {
	return energyOutput;
}

std::string HydroSource::getFuelType() {
	return "Hydro";
}
