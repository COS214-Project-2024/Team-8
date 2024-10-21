#include <exception>
#include <string>
using namespace std;

#include "EnergySource.h"
EnergySource::EnergySource() {
}

float EnergySource::getEnergyOutput() {
	return this->_energyOutput;
}

string EnergySource::getFuelType() {
	throw "Not yet implemented";
}

