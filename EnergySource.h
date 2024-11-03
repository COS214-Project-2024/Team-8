#ifndef ENERGYSOURCE_H
#define ENERGYSOURCE_H

#include <iostream>
/**
 * @file EnergySource.h
 * 
 * @brief The header file for the EnergySource class
 */
class EnergySource {
protected:
	float energyOutput;

public:
	virtual float getEnergyOutput();

	virtual std::string getFuelType() = 0;

	virtual ~EnergySource() {};
};

#endif
