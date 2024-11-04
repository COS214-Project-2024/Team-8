#include "WasteManagement.h"

WasteManagement::WasteManagement(float output) {
	this->Output = output;
	this->status = "Operational";
	this->processCapacity = 0;
	this->recycledperc = 0.0;
}

std::string WasteManagement::getStatus() {
	return this->status;
}

void WasteManagement::repairUtility() {
	std::cout << "Waste Management is being repaired..." << std::endl;
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

void WasteManagement::executeOperation() {
	std::cout << "Waste Management is operational." << std::endl;
	this->status = "Operational";
	this->recycledperc += 5;
	this->recycledperc = (int)this->recycledperc % 100;
	this->commandHistory.push_back("Operational");
}

float WasteManagement::getOutput() {
	return this->Output;
}

void WasteManagement::pauseOperation() {
	std::cout << "Waste Management is being paused..." << std::endl;
	this->status = "Paused";
	this->commandHistory.push_back("Paused");
}

void WasteManagement::setProcessCapacity(int pro) {
	this->processCapacity = pro;
}

void WasteManagement::undoChange() {
	int size = commandHistory.size();
	if(size <= 1) {
		std::cout << "No more operations to undo." << std::endl;
		return;
	}
	std::cout << "Last Operation On Waste Management being undone.." << std::endl;
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

std::string WasteManagement::getUtilityType() {
	return "Waste Management";
}

Utility* WasteManagement::clone() {
	WasteManagement* clone = new WasteManagement(this->Output);
	clone->setProcessCapacity(this->processCapacity);
	return clone;
}