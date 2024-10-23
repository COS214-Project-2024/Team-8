#include <exception>
using namespace std;

#include "CulturalCenter.h"
#include "State.h"

void CulturalCenter::requestState() {
	throw "Not yet implemented";
}

double CulturalCenter::getMaintenanceCost() {
	return this->_maintenanceCost;
}

int CulturalCenter::getPowerReq() {
	return this->_powerReq;
}

int CulturalCenter::getSewageCost() {
	return this->_sewageCost;
}

int CulturalCenter::getWaterCost() {
	throw "Not yet implemented";
}

int CulturalCenter::getWasteCost() {
	throw "Not yet implemented";
}

