#include "WaterSupply.h"

WaterSupply::WaterSupply(int curSupply) {
	this->currentSupply = curSupply;
	this->status = "Operational";
	manager = new UtilityManager();
}

std::string WaterSupply::getStatus() {
	return this->status;
}

void WaterSupply::repairUtility() {
	std::cout << "Water Supply is being repaired" << std::endl;
	this->status = "Repairing";
}

void WaterSupply::executeOperation() {
	std::cout << "Water Supply is running" << std::endl;
	this->status = "Operational";
}

int WaterSupply::getCurrentSupply() {
	return this->currentSupply;
}

void WaterSupply::pauseOperation() {
	std::cout << "Water Supply is paused" << std::endl;
	this->status = "Paused";
}

void WaterSupply::addCommand(Command* com) {
	manager->addCommand(com);
}

void WaterSupply::setMaxGallons(float max) {
	this->maxGallons = max;
}

std::string WaterSupply::getUtilityType() {
	return "WaterTreatment";
}