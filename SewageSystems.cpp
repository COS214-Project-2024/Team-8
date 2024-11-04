#include "SewageSystems.h"

/**
 * @brief Create a SewageSystems object
 * 
 * @param output The output of the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 * Command history is used to keep track of the operations done on the SewageSystems
 */
SewageSystems::SewageSystems(float output) {
	this->Output = output;
	this->status = "Operational";
	this->maxWaste = 0;
	this->blockagepercentage = 100;
	commandHistory.push_back("Operational");
}

/**
 * @brief Get the status of the SewageSystems
 * 
 * @return std::string The status of the SewageSystems
 */
std::string SewageSystems::getStatus() {
	return this->status;
}

/**
 * @brief Repare the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 * Simulates a repair operation by printing a series of '#' to the console
 */
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

/**
 * @brief Execute the operation of the SewageSystems
 * 
 * Sets the status to "Operational" and adds the status to the commandHistory
 */
void SewageSystems::executeOperation() {
	std::cout << "Sewage System is operational." << std::endl;
	this->status = "Operational";
	this->blockagepercentage -= (this->blockagepercentage * 0.20);
	this->commandHistory.push_back("Operational");
}

/**
 * @brief Get the output of the SewageSystems
 * 
 * @return float The output of the SewageSystems
 */
float SewageSystems::getOutput() {
	return this->Output;
}

/**
 * @brief Pause the operation of the SewageSystems
 * 
 * Sets the status to "Paused" and adds the status to the commandHistory
 */
void SewageSystems::pauseOperation() {
	std::cout << "Sewage System is being paused..." << std::endl;
	this->status = "Paused";
	this->blockagepercentage += (this->blockagepercentage * 0.20);
	this->commandHistory.push_back("Paused");
}

/**
 * @brief Set the maximum waste of the SewageSystems
 * 
 * @param max The maximum waste of the SewageSystems
 */
void SewageSystems::setmaxWaste(int max) {
	this->maxWaste = max;
}

/**
 * @brief Undo the last operation done on the SewageSystems
 * 
 * If the last operation was "Operational", the SewageSystems is paused
 * If the last operation was "Paused", the SewageSystems is set to operational
 * If there are no more operations to undo, a message is printed to the console
 */
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

/**
 * @brief Get the type of the SewageSystems
 * 
 * @return std::string The type of the SewageSystems
 */
std::string SewageSystems::getUtilityType() {
	return "Sewage Systems";
}

/**
 * @brief Clone the SewageSystems
 * 
 * @return Utility* The cloned SewageSystems
 */
Utility* SewageSystems::clone() {
	Utility* utility = new SewageSystems(this->Output);
	utility->setmaxWaste(this->maxWaste);
	return utility;
}

/**
 * @brief Set the output of the SewageSystems
 * 
 * @param Output The output of the SewageSystems
 */
void SewageSystems::setOutput(float Output) {
	this->Output = Output;
}
