#include <exception>
using namespace std;

#include "WindFactory.h"
#include "EnergySource.h"
#include "EnergyFactory.h"

EnergySource* WindFactory::createEnergySource(int aI) {
	throw "Not yet implemented";
}

