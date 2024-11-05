#ifndef COALSOURCE_H
#define COALSOURCE_H

#include "EnergySource.h"
/**
 * @file CoalSource.h
 * 
 * 
 * @brief The header file for the CoalSource class
 */
class CoalSource : public EnergySource {
public:
	CoalSource(float output);

	float getEnergyOutput();

	std::string getFuelType();
};

#endif
