#include <exception>
#include <string>
using namespace std;

#ifndef __HydroSource_h__
#define __HydroSource_h__

#include "EnergySource.h"

// class EnergySource;
class HydroSource;

class HydroSource: public EnergySource
{

	public: void hydroSource(int aI);

	public: float getEnergyOutput();

	public: string getFuelType();
};

#endif
