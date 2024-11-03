#ifndef WINDSOURCE_H
#define WINDSOURCE_H

#include "EnergySource.h"
/**
 * @file WindSource.h
 * 
 * 
 * @brief The header file for the WindSource class
 */
class WindSource : public EnergySource {
public:
	WindSource(float output);

	float getEnergyOutput();
	float getEnergyOutput();

	std::string getFuelType();
	std::string getFuelType();
};

#endif