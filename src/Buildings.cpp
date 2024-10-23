#include <exception>
using namespace std;

#include "Buildings.h"
#include "State.h"
#include "Government.h"
#include "ConstructionCompany.h"
#include "Resources.h"

void Buildings::requestState() {
	throw "Not yet implemented";
}

double Buildings::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int Buildings::getPowerReq() {
	return this->_powerReq;
}

int Buildings::getSewageCost() {
	return this->_sewageCost;
}

int Buildings::getWaterCost() {
	throw "Not yet implemented";
}

void Buildings::getWasteCost() {
	throw "Not yet implemented";
}

