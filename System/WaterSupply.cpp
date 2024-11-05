#include "WaterSupply.h"


WaterSupply::WaterSupply(float curSupply) {
	this->Output = curSupply;
	this->maxGallons = 1000;
	this->status = "Operational";
	this->puritypercentage = 100;
}


std::string WaterSupply::getStatus() {
	return this->status;
}


void WaterSupply::repairUtility() {
	std::cout << "Water Supply is being repaired..." << std::endl;
	int interval = 200;
	std::cout << "Repairing..." << std::endl;
	std::string progress;
	for(int i = 0; i < 30; i++) {
        progress += '#';
        std::cout << "\r" << progress << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
	std::cout << std::endl;
	this->puritypercentage += (this->puritypercentage * 0.10);
	std::cout << "Purity Percentage: " << this->puritypercentage << std::endl;
	executeOperation();
}


void WaterSupply::pauseOperation() {
	std::cout << "Water Supply is being paused..." << std::endl;
	this->status = "Paused";
	this->commandHistory.push_back("Paused");
}


void WaterSupply::executeOperation() {
	std::cout << "Water Supply is operational." << std::endl;
	this->status = "Operational";
	this->puritypercentage -= (this->puritypercentage * 0.05);
	std::cout << "Purity Percentage: " << this->puritypercentage << std::endl;
	this->commandHistory.push_back("Operational");
}


void WaterSupply::setMaxGallons(float max) {
	this->maxGallons = max;
}

float WaterSupply::getOutput() {
	return this->Output;
}

void WaterSupply::undoChange() {
	int size = commandHistory.size();
	if(size == 1) {
		std::cout << "No more operations to undo." << std::endl;
		return;
	}
	std::cout << "Last Operation On Water Supply being undone.." << std::endl;
	int interval = 200;
    std::cout << "Reverting Operation..." << std::endl;
    std::string progress;
    for(int i = 0; i < 30; i++) {
        progress += '#';
        std::cout << "\r" << progress << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    std::cout << std::endl;
	if(commandHistory[size - 1] == "Operational") {
		commandHistory.pop_back();
		pauseOperation();
	}
	else {
		commandHistory.pop_back();
		executeOperation();
	}
}


Utility* WaterSupply::clone() {
	WaterSupply* clone = new WaterSupply(this->Output);
	clone->setMaxGallons(this->maxGallons);
	return clone;
}

std::string WaterSupply::getUtilityType() {
	return "Water Supply";
}

void WaterSupply::addBuilding(Buildings* building) {
	this->buildings.push_back(building);
}

bool WaterSupply::getWater(Buildings* sender) {
	int size = buildings.size();
	for(int i = 0; i < size; i++) {
		if(buildings[i] == sender) {
			//sender->setWater(getOutput());
			std::cout << this->Output << std::endl;
			return true;
		}
	}

	std::cout << "Building is not Registered" << std::endl;

	return false;
}

