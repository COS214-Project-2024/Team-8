#include <exception>
using namespace std;

#include "LandmarkBuilding.h"
#include "State.h"
#include "Buildings.h"

void LandmarkBuilding::requestState() {
	throw "Not yet implemented";
}

double LandmarkBuilding::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int LandmarkBuilding::getPowerReq() {
	return this->_powerReq;
}

int LandmarkBuilding::getSewageCost() {
	return this->_sewageCost;
}

int LandmarkBuilding::getWaterCost() {
	throw "Not yet implemented";
}

int LandmarkBuilding::getWasteCost() {
	throw "Not yet implemented";
}

