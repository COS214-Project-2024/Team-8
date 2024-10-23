#include <exception>
using namespace std;

#include "House.h"
#include "State.h"
#include "Estate.h"

void House::requestState() {
	throw "Not yet implemented";
}

int House::getCapacity() {
	return this->_capacity;
}

Citizen* House::getListOfResident() {
	throw "Not yet implemented";
}

double House::getMaintenanceCost() {
	throw "Not yet implemented";
}

int House::getPowerReq() {
	return this->_powerReq;
}

int House::getWaterReq() {
	return this->_waterReq;
}

int House::getSewageCost() {
	return this->_sewageCost;
}

int House::getWasteCost() {
	throw "Not yet implemented";
}

