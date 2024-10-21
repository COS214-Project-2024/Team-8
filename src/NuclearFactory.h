#include <exception>
using namespace std;

#ifndef __NuclearFactory_h__
#define __NuclearFactory_h__

// #include "EnergySource.h"
#include "EnergyFactory.h"

class EnergySource;
// class EnergyFactory;
class NuclearFactory;

class NuclearFactory: public EnergyFactory
{

	public: EnergySource* createEnergySource(int aI);
};

#endif
