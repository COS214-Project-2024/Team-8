#include <exception>
using namespace std;

#include "PowerPlant.h"
#include "State.h"

void PowerPlant::requestState() {
	throw "Not yet implemented";
}

int PowerPlant::getCapacity() {
	return this->_capacity;
}

int PowerPlant::getPowerReq() {
	return this->_powerReq;
}

int PowerPlant::getWaterReq() {
	return this->_waterReq;
}

int PowerPlant::getSewageCost() {
	return this->_sewageCost;
}

int PowerPlant::getWasteCost() {
	throw "Not yet implemented";
}

int PowerPlant::getMaintenaceCost() {
	throw "Not yet implemented";
}

