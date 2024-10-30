#include "WindSource.h"

WindSource::WindSource(int output) {
	this->energyOutput = output;
}

float WindSource::getEnergyOutput() {
	return energyOutput;
}

std::string WindSource::getFuelType() {
	return "Wind";
}
