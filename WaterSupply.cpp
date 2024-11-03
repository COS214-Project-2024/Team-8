#include "WaterSupply.h"

/**
 * @brief Create a WaterSupply object
 * 
 * @param curSupply The current supply of the WaterSupply
 */
WaterSupply::WaterSupply(float curSupply) {
	this->Output = curSupply;
	this->maxGallons = 1000;
	this->status = "Operational";
	this->puritypercentage = 100;
}

/**
 * @brief returns the status of the WaterSupply
 * 
 * @return std::string The status of the WaterSupply
 */
std::string WaterSupply::getStatus() {
	return this->status;
}

/**
 * @brief Repairs the WaterSupply
 * 
 * Repairs the WaterSupply
 * Also sets the status to operational
 */
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

/**
 * @brief Pauses the operation of the WaterSupply
 * 
 * Sets the status to paused
 */
void WaterSupply::pauseOperation() {
	std::cout << "Water Supply is being paused..." << std::endl;
	this->status = "Paused";
	this->commandHistory.push_back("Paused");
}

/**
 * @brief Executes the operation of the WaterSupply
 * 
 * Sets the status to operational
 */
void WaterSupply::executeOperation() {
	std::cout << "Water Supply is operational." << std::endl;
	this->status = "Operational";
	this->puritypercentage -= (this->puritypercentage * 0.05);
	std::cout << "Purity Percentage: " << this->puritypercentage << std::endl;
	this->commandHistory.push_back("Operational");
}

/**
 * @brief Sets the max gallons of the WaterSupply
 * 
 * @param max The max gallons of the WaterSupply
 */
void WaterSupply::setMaxGallons(float max) {
	this->maxGallons = max;
}

/**
 * @brief Gets the output of the WaterSupply
 * 
 * @return float The output of the WaterSupply
 */
float WaterSupply::getOutput() {
	return this->Output;
}

/**
 * @brief Undoes the last change to the WaterSupply
 * 
 * Undoes the last change to the WaterSupply
 * Also sets the status to paused
 */
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

/**
 * @brief Clones the WaterSupply
 * 
 * @return Utility* The cloned WaterSupply
 */
Utility* WaterSupply::clone() {
	WaterSupply* clone = new WaterSupply(this->Output);
	clone->setMaxGallons(this->maxGallons);
	return clone;
}

/**
 * @brief Get the utility type of the WaterSupply
 * 
 * @return std::string The utility type of the WaterSupply
 */
std::string WaterSupply::getUtilityType() {
	return "Water Supply";
}
