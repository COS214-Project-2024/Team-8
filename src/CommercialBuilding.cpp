#include <exception>
using namespace std;

#include "CommercialBuilding.h"
#include "State.h"
#include "Buildings.h"

void CommercialBuilding::requestState() {
	throw "Not yet implemented";
}

double CommercialBuilding::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int CommercialBuilding::getPowerReq() {
	return this->_powerReq;
}

int CommercialBuilding::getSewageCost() {
	return this->_sewageCost;
}

int CommercialBuilding::getWaterCost() {
	throw "Not yet implemented";
}

int CommercialBuilding::getWasteCost() {
	throw "Not yet implemented";
}

