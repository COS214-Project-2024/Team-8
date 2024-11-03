#include "UtilityManager.h"

/**
 * @brief Create a UtilityManager object
 * 
 * The constructor for the UtilityManager class
 */
UtilityManager::UtilityManager() {
	std::cout << "UtilityManager created" << std::endl;
}

/**
 * @brief Executes the Waste Management utility
 * 
 * Executes the Waste Management utility
 */
void UtilityManager::executeWaste() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->commands[i])) {
			if(start->getUtilityType() == "Waste Management") {
				start->execute();
			}
		}
	}
}

/**
 * @brief Undoes the last command
 * 
 * Undoes the last command that was executed
 */
void UtilityManager::undoCommand() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(UndoCommand* stop = dynamic_cast<UndoCommand*>(this->commands[i])) {
			stop->execute();
		}
	}
}

/**
 * @brief Executes Load Shedding
 * 
 * Load Shedding is a utility that is used to stop the power plant
 */
void UtilityManager::LoadShedding() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StopCommand* stop = dynamic_cast<StopCommand*>(this->commands[i])) {
			if(stop->getUtilityType() == "Power Plant") {
				stop->execute();
			}
		}
	}
}

/**
 * @brief Executes Unfilled Dam
 * 
 * Unfilled Dam is a utility that is used to stop the water treatment plant
 */
void UtilityManager::UnfilledDam() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StopCommand* stop = dynamic_cast<StopCommand*>(this->commands[i])) {
			if(stop->getUtilityType() == "WaterTreatment") {
				stop->execute();
			}
		}
	}
}

/**
 * @brief Executes the Sewage Plant
 * 
 * Executes the Sewage Plant utility
 */
void UtilityManager::executeSewage() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->commands[i])) {
			if(start->getUtilityType() == "SewagePlant") {
				start->execute();
			}
		}
	}
}

/**
 * @brief Executes the Water Treatment Plant
 * 
 * Executes the Water Treatment Plant utility
 */
void UtilityManager::executeWater() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->commands[i])) {
			if(start->getUtilityType() == "Waste Management") {
				start->execute();
			}
		}
	}
}

/**
 * @brief Executes the Power Plant
 * 
 * Executes the Power Plant utility
 */
void UtilityManager::executeElectricity() {
	int size = this->commands.size();
	for(int i = 0; i < size; i++) {
		if(StartCommand* start = dynamic_cast<StartCommand*>(this->commands[i])) {
			if(start->getUtilityType() == "PowerPlant") {
				start->execute();
			}
		}
	}
}

/**
 * @brief Add a command to the UtilityManager
 * 
 * @param com The command to add
 */
void UtilityManager::addCommand(Command* com) {
	this->commands.push_back(com);
}
