#ifndef NUCLEARSOURCE_H
#define NUCLEARSOURCE_H

#include "EnergySource.h"
class NuclearSource : public EnergySource {
public:
	NuclearSource(int output);

	float getEnergyOutput();

	std::string getFuelType();
};

#endif
