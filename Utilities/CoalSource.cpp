#include "CoalSource.h"

CoalSource::CoalSource(float output) {
	this->energyOutput = output;
}

float CoalSource::getEnergyOutput() {
	return energyOutput;
}

std::string CoalSource::getFuelType() {
	return "Coal";
}
