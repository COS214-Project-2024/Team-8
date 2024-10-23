#include <exception>
using namespace std;

#include "Park.h"
#include "State.h"

void Park::requestState() {
	throw "Not yet implemented";
}

double Park::getMaintenanceCost() {
	throw "Not yet implemented";
}

int Park::getPowerReq() {
	return this->_powerReq;
}

int Park::getSewageCost() {
	return this->_sewageCost;
}

int Park::getWaterCost() {
	throw "Not yet implemented";
}

int Park::getWasteCost() {
	throw "Not yet implemented";
}

