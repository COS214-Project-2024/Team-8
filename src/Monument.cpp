#include <exception>
using namespace std;

#include "Monument.h"
#include "State.h"

void Monument::requestState() {
	throw "Not yet implemented";
}

double Monument::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int Monument::getPowerReq() {
	return this->_powerReq;
}

int Monument::getSewageCost() {
	return this->_sewageCost;
}

int Monument::getWaterCost() {
	throw "Not yet implemented";
}

int Monument::getWasteCost() {
	throw "Not yet implemented";
}

