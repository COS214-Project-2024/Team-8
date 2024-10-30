#include "Utility.h"

std::string Utility::getStatus() {
	return this->status;
}

void Utility::setFuel(EnergySource* fuel) {
	throw "NOT A MEMBER OF SAID CLASS";
}

std::string Utility::getEnergyType() {
	throw "NOT A MEMBER OF SAID CLASS";
}

void Utility::setmaxWaste(int max){
	throw "NOT A MEMBER OF SAID CLASS";
}

int Utility::getCurrentSupply() {
	throw "NOT A MEMBER OF SAID CLASS";
}

int Utility::getCurrentLoad() {
	throw "NOT A MEMBER OF SAID CLASS";
}
void Utility::setProcessCapacity(int pro){
	throw "NOT A MEMBER OF SAID CLASS";
}

void Utility::setMaxWatts(float max){
	throw "NOT A MEMBER OF SAID CLASS";
}

void Utility::setMaxGallons(float max){
	throw "NOT A MEMBER OF SAID CLASS";
}

int Utility::getCurrentOutput() {
	throw "NOT A MEMBER OF SAID CLASS";
}

float Utility::getMaxWatts() {
	throw "NOT A MEMBER OF SAID CLASS";
}

Utility::~Utility() {
	delete manager;
}
