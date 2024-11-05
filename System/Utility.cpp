#include "Utility.h"


float Utility::getOutput() {
	return this->Output;
}


void Utility::setMaxWatts(float max) {
	throw "NOT A MEMBER OF SAID CLASS";
}


void Utility::setmaxWaste(int max) {
	throw "NOT A MEMBER OF SAID CLASS";
}


void Utility::setMaxGallons(float max) {
	throw "NOT A MEMBER OF SAID CLASS";
}


void Utility::setFuel(EnergySource* fuel) {
	throw "NOT A MEMBER OF SAID CLASS";
}


void Utility::switchFuel() {
	throw "NOT A MEMBER OF SAID CLASS";
}


std::string Utility::getEnergyType() {
	throw "NOT A MEMBER OF SAID CLASS";
}


void Utility::setOutput(float Output) {
	this->Output = Output;
}

void Utility::setProcessCapacity(int pro) {
	throw "NOT A MEMBER OF SAID CLASS";
}

bool Utility::getPower(Buildings* sender){
	std::cout << "Power power sent to building" << std::endl;
	return true;
}

bool Utility::getWater(Buildings* sender){
	std::cout << "Water sent to building" << std::endl;
	return true;
}

bool Utility::cleanWaste(Buildings* sender){
	std::cout << "Waste cleaned" << std::endl;
	return true;
}

bool Utility::cleanSewage(Buildings* sender){
	std::cout << "Sewage cleaned" << std::endl;
	return true;
}