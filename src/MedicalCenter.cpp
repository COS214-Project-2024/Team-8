#include <exception>
using namespace std;

#include "MedicalCenter.h"
#include "State.h"

void MedicalCenter::requestState() {
	throw "Not yet implemented";
}

double MedicalCenter::getMaintenanceCost() {
	return this->_maintenanceCost;
}

double MedicalCenter::getSewageCost() {
	throw "Not yet implemented";
}

float MedicalCenter::getHealthCare() {
	throw "Not yet implemented";
}

int MedicalCenter::getPowerReq() {
	return this->_powerReq;
}

int MedicalCenter::getWaterReq() {
	return this->_waterReq;
}

