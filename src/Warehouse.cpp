#include <exception>
using namespace std;

#include "Warehouse.h"
#include "State.h"

void Warehouse::requestState() {
	throw "Not yet implemented";
}

int Warehouse::getCapacity() {
	return this->_capacity;
}

int Warehouse::getPowerReq() {
	return this->_powerReq;
}

int Warehouse::getWaterReq() {
	return this->_waterReq;
}

in Warehouse::getSewageCost() {
	throw "Not yet implemented";
}

int Warehouse::getWasteCost() {
	throw "Not yet implemented";
}

int Warehouse::getMaintenanceCost() {
	throw "Not yet implemented";
}

