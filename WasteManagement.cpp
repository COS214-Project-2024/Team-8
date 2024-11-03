#include "WasteManagement.h"

/**
 * @brief Create a WasteManagement object
 * 
 * @param output The output of the WasteManagement
 * 
 * The constructor for the WasteManagement class
 */
WasteManagement::WasteManagement(float output) {
	this->Output = output;
	this->status = "Operational";
	this->processCapacity = 0;
	this->recycledperc = 0.0;
}

/**
 * @brief Get the status of the WasteManagement
 * 
 * @return std::string The status of the WasteManagement
 */
std::string WasteManagement::getStatus() {
	return this->status;
}

/**
 * @brief Repair the WasteManagement
 * 
 * Repairs the WasteManagement
 * Also sets the status to operational
 */
void WasteManagement::repairUtility() {
	std::cout << "Waste Management is being repaired..." << std::endl;
	int interval = 500;
	std::cout << "Repairing..." << std::endl;
	for(int i = 0; i < 30; i++) {
		std::cout << std::string(i, '#') << std::endl;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(interval));
	}
	std::cout << std::string(30, '#') << std::endl;
	executeOperation();
}

/**
 * @brief Execute the operation of the WasteManagement
 * 
 * Sets the status to operational
 */
void WasteManagement::executeOperation() {
	std::cout << "Waste Management is operational." << std::endl;
	this->status = "Operational";
	this->recycledperc += 5;
	this->recycledperc = (int)this->recycledperc % 100;
	this->commandHistory.push_back("Operational");
}

/**
 * @brief Get the output of the WasteManagement
 * 
 * @return float The output of the WasteManagement
 */
float WasteManagement::getOutput() {
	return this->Output;
}

/**
 * @brief Pause the operation of the WasteManagement
 * 
 * Sets the status to paused
 */
void WasteManagement::pauseOperation() {
	std::cout << "Waste Management is being paused..." << std::endl;
	this->status = "Paused";
	this->commandHistory.push_back("Paused");
}

/**
 * @brief Set the process capacity of the WasteManagement
 * 
 * @param pro The process capacity of the WasteManagement
 */
void WasteManagement::setProcessCapacity(int pro) {
	this->processCapacity = pro;
}

/**
 * @brief Undo the last change to the WasteManagement
 * 
 * Undoes the last change to the WasteManagement
 */
void WasteManagement::undoChange() {
	int size = commandHistory.size();
	if(size == 1) {
		std::cout << "No more operations to undo." << std::endl;
		return;
	}
	std::cout << "Last Operation On Waste Management being undone.." << std::endl;
	int interval = 500;
	std::cout << "Reverting Operation..." << std::endl;
	for(int i = 0; i < 30; i++) {
		std::cout << std::string(i, '#') << std::endl;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(interval));
	}
	std::cout << std::string(30, '#') << std::endl;
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
 * @brief Get the utility type of the WasteManagement
 * 
 * @return std::string The utility type of the WasteManagement
 */
std::string WasteManagement::getUtilityType() {
	return "Waste Management";
}

/**
 * @brief Clone the WasteManagement
 * 
 * @return Utility* The cloned WasteManagement
 */
Utility* WasteManagement::clone() {
	WasteManagement* clone = new WasteManagement(this->Output);
	clone->setProcessCapacity(this->processCapacity);
	return clone;
}
