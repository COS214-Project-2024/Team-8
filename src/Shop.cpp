#include <exception>
using namespace std;

#include "Shop.h"
#include "State.h"
#include "Mall.h"

void Shop::requestState() {
	throw "Not yet implemented";
}

double Shop::getMaintenaceCost() {
	throw "Not yet implemented";
}

int Shop::getSewageCost() {
	return this->_sewageCost;
}

int Shop::getWasteCost() {
	throw "Not yet implemented";
}

void Shop::getWaterReq() {
	throw "Not yet implemented";
}

int Shop::getEmployment() {
	return this->_employment;
}

int Shop::getIncome() {
	throw "Not yet implemented";
}

void Shop::getPowerReq() {
	throw "Not yet implemented";
}

