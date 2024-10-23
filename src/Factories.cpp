#include <exception>
using namespace std;

#include "Factories.h"
#include "State.h"

void Factories::requestState() {
	throw "Not yet implemented";
}

int Factories::getCapacity() {
	return this->_capacity;
}

int Factories::getPowerReq() {
	return this->_powerReq;
}

int Factories::getWaterReq() {
	return this->_waterReq;
}

int Factories::getSewageCost() {
	return this->_sewageCost;
}

int Factories::getWasteCost() {
	throw "Not yet implemented";
}

double Factories::getMaintanenceCost() {
	throw "Not yet implemented";
}

