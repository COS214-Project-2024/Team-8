#ifndef HYDROSOURCE_H
#define HYDROSOURCE_H

#include "EnergySource.h"
class HydroSource : public EnergySource {
public:
	HydroSource(int output);

	float getEnergyOutput();

	std::string getFuelType();
};

#endif
