#include <exception>
using namespace std;

#include "IndustrialBuilding.h"
#include "State.h"
#include "Buildings.h"

void IndustrialBuilding::requestState() {
	throw "Not yet implemented";
}

double IndustrialBuilding::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int IndustrialBuilding::getPowerReq() {
	return this->_powerReq;
}

int IndustrialBuilding::getSewageCost() {
	return this->_sewageCost;
}

int IndustrialBuilding::getWaterCost() {
	throw "Not yet implemented";
}

int IndustrialBuilding::getWasteCost() {
	throw "Not yet implemented";
}

