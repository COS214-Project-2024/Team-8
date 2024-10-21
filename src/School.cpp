#include <exception>
using namespace std;

#include "School.h"
#include "State.h"

void School::requestState() {
	throw "Not yet implemented";
}

double School::getMaintenanceCost() {
	return this->_maintenanceCost;
}

double School::getSewageCost() {
	throw "Not yet implemented";
}

int School::getPowerReq() {
	return this->_powerReq;
}

int School::getWaterReq() {
	return this->_waterReq;
}

int School::getEducation() {
	throw "Not yet implemented";
}

