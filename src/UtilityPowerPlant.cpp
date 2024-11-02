#include "UtilityPowerPlant.h"

UtilityPowerPlant::UtilityPowerPlant(int output) {
	this->currentOutput = output;
	this->maximumWatts = output;
	this->status = "Operational";
	manager = new UtilityManager();
	//fuel construction done outside class
}

std::string UtilityPowerPlant::getEnergyType() {
	return fuel->getFuelType();
}

void UtilityPowerPlant::executeOperation() {
	std::cout << "Power Plant is running" << std::endl;
	this->status = "Operational";
}

void UtilityPowerPlant::repairUtility() {
	std::cout << "Power Plant is being repaired" << std::endl;
	this->status = "Repairing";
}

void UtilityPowerPlant::undoChange() {
	manager->undoCommand();
}

std::string UtilityPowerPlant::getStatus() {
	return this->status;
}

void UtilityPowerPlant::pauseOperation() {
	std::cout << "Power Plant is paused" << std::endl;
	this->status = "Paused";
}

void UtilityPowerPlant::addCommand(Command* com) {
	manager->addCommand(com);
}

void UtilityPowerPlant::setMaxWatts(float max) {
	this->maximumWatts = max;
}

void UtilityPowerPlant::setFuel(EnergySource* fuel) {
	if(fuel != nullptr) {
		delete fuel;
	}
	fuel = fuel;
}

float UtilityPowerPlant::getMaxWatts() {
	return this->maximumWatts;
}

int UtilityPowerPlant::getCurrentOutput() {
	return this->currentOutput;
}

std::string UtilityPowerPlant::getUtilityType() {
	return "PowerPlant";
}
