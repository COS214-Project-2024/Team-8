#include "WaterSupply.h"

/**
 * @brief Create a WaterSupply object
 * 
 * @param curSupply The current supply of the WaterSupply
 */
WaterSupply::WaterSupply(float curSupply) {
    this->Output = curSupply;
    this->maxGallons = __INT_MAX__; // Assuming no limit initially
    this->status = "Operational";
    this->purityPercentage = 100; // Default purity percentage
}
WaterSupply::WaterSupply(int gallons,  float purity) {
    this->maxGallons = gallons;
    this->purityPercentage = purity;
}

std::string WaterSupply::getEnergyType()
{
    return "Water";
}

/**
 * @brief returns the status of the WaterSupply
 * 
 * @return std::string The status of the WaterSupply
 */
std::string WaterSupply::getStatus() {
    return this->status;
}
Utility* WaterSupply::clone() {
    return new WaterSupply(this->maxGallons, this->purityPercentage); // Create a new instance
}

/**
 * @brief Repairs the WaterSupply
 * 
 * Repairs the WaterSupply and sets the status to operational
 */
void WaterSupply::repairUtility() {
    std::cout << "Water Supply is being repaired..." << std::endl;
    std::cout << "Repairing..." << std::endl;
    for (int i = 0; i < 30; i++) {
        std::cout << std::string(i, '#') << std::endl;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Use a literal value instead
    }
    std::cout << std::string(30, '#') << std::endl;
    executeOperation(); // Set status back to operational
}

/**
 * @brief Undoes the last change to the WaterSupply
 * 
 * Undoes the last change to the WaterSupply
 * Also sets the status to paused if the last operation was "Operational"
 */
void WaterSupply::undoChange() {
    int size = commandHistory.size();
    if (size <= 1) {
        std::cout << "No more operations to undo." << std::endl;
        return;
    }
    std::cout << "Last Operation on Water Supply being undone..." << std::endl;
    std::cout << "Reverting Operation..." << std::endl;
    for (int i = 0; i < 30; i++) {
        std::cout << std::string(i, '#') << std::endl;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Use a literal value instead
    }
    std::cout << std::string(30, '#') << std::endl;

    // Check the last command and revert it
    if (commandHistory[size - 1] == "Operational") {
        commandHistory.pop_back();
        pauseOperation();
    } else {
        commandHistory.pop_back();
        executeOperation();
    }
}


/**
 * @brief Pauses the operation of the WaterSupply
 * 
 * Sets the status to paused
 */
void WaterSupply::pauseOperation() {
    Utility::pauseOperation(); // Call base class method
}

/**
 * @brief Executes the operation of the WaterSupply
 * 
 * Sets the status to operational
 */
void WaterSupply::executeOperation() {
    std::cout << "Water Supply is operational." << std::endl;
    this->status = "Operational";
    this->commandHistory.push_back("Operational");
}

/**
 * @brief Sets the max gallons of the WaterSupply
 * 
 * @param max The max gallons of the WaterSupply
 */
void WaterSupply::setMaxGallons(float max) {
    this->maxGallons = max;
    std::cout << "Max gallons set to " << max << " for Water Supply." << std::endl;
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
 * @brief Get the utility type of the WaterSupply
 * 
 * @return std::string The utility type of the WaterSupply
 */
std::string WaterSupply::getUtilityType() {
    return "Water Supply";
}
