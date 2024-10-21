#include <exception>
using namespace std;

#include "Apartment.h"
#include "State.h"

void Apartment::requestState() {
	throw "Not yet implemented";
}

int Apartment::getCapacity() {
	return this->_capacity;
}

Citizen* Apartment::getListOfResidents() {
	return this->_listOfResidents;
}

double Apartment::getMaiantenanceCost() {
	throw "Not yet implemented";
}

int Apartment::getPowerReq() {
	return this->_powerReq;
}

int Apartment::getWaterReq() {
	return this->_waterReq;
}

int Apartment::getSewageCost() {
	return this->_sewageCost;
}

int Apartment::getWasteCost() {
	throw "Not yet implemented";
}

