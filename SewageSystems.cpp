#include "SewageSystems.h"


SewageSystems::SewageSystems(float output) {
	this->Output = output;
	this->status = "Operational";
	this->maxWaste = 0;
	this->blockagepercentage = 100;
	commandHistory.push_back("Operational");
}

std::string SewageSystems::getStatus() {
	return this->status;
}


void SewageSystems::repairUtility() {
	std::cout << "Sewage System is being repaired..." << std::endl;
	int interval = 200;
	std::cout << "Repairing..." << std::endl;
    std::string progress;
    for(int i = 0; i < 30; i++) {
        progress += '#';
        std::cout << "\r" << progress << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    std::cout << std::endl;
	executeOperation();
}


void SewageSystems::executeOperation() {
	std::cout << "Sewage System is operational." << std::endl;
	this->status = "Operational";
	this->blockagepercentage -= (this->blockagepercentage * 0.20);
	this->commandHistory.push_back("Operational");
}


float SewageSystems::getOutput() {
	return this->Output;
}


void SewageSystems::pauseOperation() {
	std::cout << "Sewage System is being paused..." << std::endl;
	this->status = "Paused";
	this->blockagepercentage += (this->blockagepercentage * 0.20);
	this->commandHistory.push_back("Paused");
}


void SewageSystems::setmaxWaste(int max) {
	this->maxWaste = max;
}


void SewageSystems::undoChange() {
	int size = commandHistory.size();
	if(size <= 1) {
		std::cout << "No more operations to undo." << std::endl;
		return;
	}
	std::cout << "Last Operation On sewage being undone.." << std::endl;
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


std::string SewageSystems::getUtilityType() {
	return "Sewage Systems";
}


Utility* SewageSystems::clone() {
	Utility* utility = new SewageSystems(this->Output);
	utility->setmaxWaste(this->maxWaste);
	return utility;
}


void SewageSystems::setOutput(float Output) {
	this->Output = Output;
}


void SewageSystems::addBuilding(Buildings* building) {
	this->buildings.push_back(building);
}


bool SewageSystems::cleanSewage(Buildings* sender) {
	int size = buildings.size();
	for(int i = 0; i < size; i++) {
		if(buildings[i] == sender) {
			//sender->cleanSewage(getOutput());
			std::cout << this->Output << std::endl;

			return true;
		}
	}

	std::cout << "Building is not registered" << std::endl;

	return false;
}

