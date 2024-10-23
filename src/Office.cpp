#include <exception>
using namespace std;

#include "Office.h"
#include "State.h"

void Office::requestState() {
	throw "Not yet implemented";
}

int Office::getIncome() {
	throw "Not yet implemented";
}

int Office::getEmployment() {
	return this->_employment;
}

double Office::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int Office::getPowerReq() {
	return this->_powerReq;
}

int Office::getWatereReq() {
	throw "Not yet implemented";
}

int Office::getSewageCost() {
	return this->_sewageCost;
}

int Office::getWasteCost() {
	throw "Not yet implemented";
}

