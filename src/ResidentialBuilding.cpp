#include <exception>
using namespace std;

#include "ResidentialBuilding.h"
#include "State.h"
#include "Buildings.h"

void ResidentialBuilding::requestState() {
	throw "Not yet implemented";
}

double ResidentialBuilding::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int ResidentialBuilding::getSewageCost() {
	return this->_sewageCost;
}

int ResidentialBuilding::getWaterCost() {
	throw "Not yet implemented";
}

int ResidentialBuilding::getPowerReq() {
	return this->_powerReq;
}

void ResidentialBuilding::getWaterReq() {
	throw "Not yet implemented";
}

int ResidentialBuilding::getWasteCost() {
	throw "Not yet implemented";
}

