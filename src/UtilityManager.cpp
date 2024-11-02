#include "UtilityManager.h"

UtilityManager::UtilityManager() {
	std::cout << "UtilityManager created" << std::endl;
}

void UtilityManager::executeWaste() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->history[i])) {
			if(start->getUtilityType() == "WasteTreatment") {
				start->execute();
			}
		}
	}
}

void UtilityManager::undoCommand() {
	this->history.pop_back();
	Command* com = this->history.back();
	com->execute();
}

void UtilityManager::LoadShedding() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StopCommand* stop = dynamic_cast<StopCommand*>(this->history[i])) {
			if(stop->getUtilityType() == "PowerPlant") {
				stop->execute();
			}
		}
	}
}

void UtilityManager::UnfilledDam() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StopCommand* stop = dynamic_cast<StopCommand*>(this->history[i])) {
			if(stop->getUtilityType() == "WaterTreatment") {
				stop->execute();
			}
		}
	}
}

void UtilityManager::executeSewage() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->history[i])) {
			if(start->getUtilityType() == "SewagePlant") {
				start->execute();
			}
		}
	}
}

void UtilityManager::executeWater() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->history[i])) {
			if(start->getUtilityType() == "WaterTreatment") {
				start->execute();
			}
		}
	}
}

void UtilityManager::executeElectricity() {
	int size = this->history.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->history[i])) {
			if(start->getUtilityType() == "PowerPlant") {
				start->execute();
			}
		}
	}
}

void UtilityManager::addCommand(Command* com) {
	this->history.push_back(com);
}
