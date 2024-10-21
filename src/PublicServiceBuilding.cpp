#include <exception>
using namespace std;

#include "PublicServiceBuilding.h"
#include "State.h"
#include "Buildings.h"

void PublicServiceBuilding::requestState() {
	throw "Not yet implemented";
}

double PublicServiceBuilding::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int PublicServiceBuilding::getPowerReq() {
	return this->_powerReq;
}

int PublicServiceBuilding::getSewageCost() {
	return this->_sewageCost;
}

int PublicServiceBuilding::getWaterCost() {
	throw "Not yet implemented";
}

int PublicServiceBuilding::getWasteCost() {
	throw "Not yet implemented";
}

