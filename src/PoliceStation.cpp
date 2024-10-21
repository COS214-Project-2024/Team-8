#include <exception>
using namespace std;

#include "PoliceStation.h"
#include "State.h"

void PoliceStation::requestState() {
	throw "Not yet implemented";
}

int PoliceStation::getEmployment() {
	return this->_employment;
}

double PoliceStation::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int PoliceStation::getPowerReq() {
	return this->_powerReq;
}

int PoliceStation::getWaterReq() {
	return this->_waterReq;
}

int PoliceStation::getSewageCost() {
	return this->_sewageCost;
}

float PoliceStation::getSecurityCoverage() {
	return this->_securityCoverage;
}

