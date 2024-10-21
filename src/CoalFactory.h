#include <exception>
using namespace std;

#ifndef __CoalFactory_h__
#define __CoalFactory_h__

// #include "EnergySource.h"
#include "EnergyFactory.h"

class EnergySource;
// class EnergyFactory;
class CoalFactory;

class CoalFactory: public EnergyFactory
{

	public: EnergySource* createEnergySource(int aI);
};

#endif
