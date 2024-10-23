#include <exception>
#include <string>
using namespace std;

#ifndef __EnergySource_h__
#define __EnergySource_h__

class EnergySource;

__abstract class EnergySource
{
	protected: float _energyOutput;

	public: EnergySource();

	public: float getEnergyOutput();

	public: virtual string getFuelType() = 0;
};

#endif
