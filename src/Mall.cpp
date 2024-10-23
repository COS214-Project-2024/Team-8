#include <exception>
using namespace std;

#include "Mall.h"
#include "State.h"
#include "CommComponent.h"

void Mall::requestState() {
	throw "Not yet implemented";
}

int Mall::getIncome() {
	throw "Not yet implemented";
}

int Mall::getEmployment() {
	return this->_employment;
}

double Mall::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int Mall::getWaterReq() {
	return this->_waterReq;
}

int Mall::getPowerReq() {
	return this->_powerReq;
}

int Mall::getSewageCost() {
	return this->_sewageCost;
}

int Mall::getWasteCost() {
	throw "Not yet implemented";
}

void Mall::add(CommComponent aParam) {
	throw "Not yet implemented";
}

void Mall::remove(CommComponent aParam) {
	throw "Not yet implemented";
}

CommComponent Mall::getChild() {
	throw "Not yet implemented";
}

void Mall::add(EstateComponent aParam) {
	throw "Not yet implemented";
}

void Mall::remove(EstateComponent aParam) {
	throw "Not yet implemented";
}

void Mall::getChild(EstateComponent aParam) {
	throw "Not yet implemented";
}

