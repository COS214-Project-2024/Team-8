#include <exception>
using namespace std;

#include "TownHouse.h"
#include "State.h"
#include "Estate.h"

void TownHouse::requestState() {
	throw "Not yet implemented";
}

int TownHouse::getCapacity() {
	return this->_capacity;
}

Citizen* TownHouse::getListOfResidents() {
	return this->_listOfResidents;
}

int TownHouse::getPowerReq() {
	return this->_powerReq;
}

int TownHouse::getWaterReq() {
	return this->_waterReq;
}

int TownHouse::getSewageCost() {
	return this->_sewageCost;
}

int TownHouse::getWasteCost() {
	throw "Not yet implemented";
}

double TownHouse::getMaintanenceCost() {
	throw "Not yet implemented";
}

