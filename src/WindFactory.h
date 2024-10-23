#include <exception>
using namespace std;

#ifndef __WindFactory_h__
#define __WindFactory_h__

// #include "EnergySource.h"
#include "EnergyFactory.h"

class EnergySource;
// class EnergyFactory;
class WindFactory;

class WindFactory: public EnergyFactory
{

	public: EnergySource* createEnergySource(int aI);
};

#endif
