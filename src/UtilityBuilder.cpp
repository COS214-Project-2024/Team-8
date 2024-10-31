#include "UtilityBuilder.h"

WaterSupply* UtilityBuilder::getWaterManager() {
	throw "NOT A MEMBER OF SAID CLASS";
}

WasteManagement* UtilityBuilder::getWasterManager() {
	throw "NOT A MEMBER OF SAID CLASS";
}

SewageSystems* UtilityBuilder::getSewageSystem() {
	throw "NOT A MEMBER OF SAID CLASS";
}

void UtilityBuilder::setMaxWaste(int max) {
	throw "NOT A MEMBER OF SAID CLASS";
}

void UtilityBuilder::setCapacity(int max) {
	throw "NOT A MEMBER OF SAID CLASS";
}

void UtilityBuilder::setMaxGallons(int max) {
	throw "NOT A MEMBER OF SAID CLASS";
}

void UtilityBuilder::setMaxWatts(float max) {
	throw "NOT A MEMBER OF SAID CLASS";
}

void UtilityBuilder::switchFuel() {
	throw "NOT A MEMBER OF SAID CLASS";
}

UtilityBuilder::UtilityBuilder() {
	std::cout<<"Utility Builder Initialized"<<std::endl;
}

UtilityBuilder::~UtilityBuilder() {
	delete this->utility;
}
