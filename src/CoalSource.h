#include <exception>
#include <string>
using namespace std;

#ifndef __CoalSource_h__
#define __CoalSource_h__

#include "EnergySource.h"

// class EnergySource;
class CoalSource;

class CoalSource: public EnergySource
{

	public: void coalSource(int aI);

	public: float getEnergyOutput();

	public: string getFuelType();
};

#endif
