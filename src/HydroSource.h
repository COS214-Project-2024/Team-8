#ifndef HYDROSOURCE_H
#define HYDROSOURCE_H

#include "EnergySource.h"
/**
 * @file HydroSource.h
 * 
 * @brief The header file for the HydroSource class
 */
class HydroSource : public EnergySource {
public:
	HydroSource(float output);

	float getEnergyOutput();

	std::string getFuelType();
};

#endif
