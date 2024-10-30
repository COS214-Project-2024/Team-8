#ifndef ENERGYSOURCE_H
#define ENERGYSOURCE_H

#include <iostream>
class EnergySource {
protected:
	float energyOutput;

public:
	virtual float getEnergyOutput() = 0;

	virtual std::string getFuelType() = 0;
};

#endif
