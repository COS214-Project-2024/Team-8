#include "WasteManagement.h"

WasteManagement::WasteManagement(int curload) {
	this->currentload = curload;
	this->recycledperc = 0;
	this->processCapacity = curload*2;
	this->status = "Operational";
	manager = new UtilityManager();
}

std::string WasteManagement::getStatus() {
	return this->status;
}

void WasteManagement::repairUtility() {
	std::cout << "Waste Management is being repaired" << std::endl;
	this->status = "Repairing";
}

void WasteManagement::executeOperation() {
	std::cout << "Waste Management is running" << std::endl;
	this->status = "Operational";
}

int WasteManagement::getCurrentLoad() {
	return this->currentload;
}

void WasteManagement::undoChange() {
	manager->undoCommand();
}

void WasteManagement::pauseOperation() {
	std::cout << "Waste Management is paused" << std::endl;
	this->status = "Paused";
}

void WasteManagement::addCommand(Command* com) {
	manager->addCommand(com);
}

void WasteManagement::setProcessCapacity(int pro) {
	this->processCapacity = pro;
}

std::string WasteManagement::getUtilityType() {
	return "WasteTreatment";
}
