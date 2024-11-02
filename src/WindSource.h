#ifndef WINDSOURCE_H
#define WINDSOURCE_H

#include "EnergySource.h"
class WindSource : public EnergySource {
public:
	WindSource(int output);

	float getEnergyOutput();

	std::string getFuelType();
};

#endif
