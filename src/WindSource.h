#include <exception>
#include <string>
using namespace std;

#ifndef __WindSource_h__
#define __WindSource_h__

#include "EnergySource.h"

// class EnergySource;
class WindSource;

class WindSource: public EnergySource
{

	public: void windSource(int aI);

	public: float getEnergyOutput();

	public: string getFuelType();
};

#endif
