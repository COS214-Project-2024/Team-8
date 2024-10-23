#include <exception>
using namespace std;

#ifndef __HydroFactory_h__
#define __HydroFactory_h__

// #include "EnergySource.h"
#include "EnergyFactory.h"

class EnergySource;
// class EnergyFactory;
class HydroFactory;

class HydroFactory: public EnergyFactory
{

	public: EnergySource* createEnergySource(int aI);
};

#endif
