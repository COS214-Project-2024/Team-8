#include <exception>
#include <string>
using namespace std;

#ifndef __NuclearSource_h__
#define __NuclearSource_h__

#include "EnergySource.h"

// class EnergySource;
class NuclearSource;

class NuclearSource: public EnergySource
{

	public: void nuclearSource(int aI);

	public: float getEnergyOutput();

	public: string getFuelType();
};

#endif
