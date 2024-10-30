#include "NuclearSource.h"

NuclearSource::NuclearSource(int output) {
	this->energyOutput = output;
}

float NuclearSource::getEnergyOutput() {
	return energyOutput;
}

std::string NuclearSource::getFuelType() {
	return "Nuclear";
}
