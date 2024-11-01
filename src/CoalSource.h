#ifndef COALSOURCE_H
#define COALSOURCE_H

#include "EnergySource.h"
class CoalSource : public EnergySource {
public:
	CoalSource(float output);

	float getEnergyOutput() override;

	std::string getFuelType() override;
};

#endif
