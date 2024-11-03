#include "UtilityPowerPlant.h"

/**
 * @brief Create a UtilityPowerPlant object
 * 
 * @param output The output of the UtilityPowerPlant
 * 
 * The constructor for the UtilityPowerPlant class
 * Also sets the fuel using the switchFuel function
 */
UtilityPowerPlant::UtilityPowerPlant(float output) {
	this->Output = output;
	this->maximumWatts = output * 2;
	this->fuel = nullptr;
	switchFuel();
}

/**
 * @brief Get the status of the UtilityPowerPlant
 * 
 * @return std::string The status of the UtilityPowerPlant
 */
std::string UtilityPowerPlant::getStatus() {
	return this->status;
}

/**
 * @brief Repair the UtilityPowerPlant
 * 
 * Repairs the UtilityPowerPlant
 * Also sets the status to operational
 */
void UtilityPowerPlant::repairUtility() {
	std::cout << "Power Plant is being repaired..." << std::endl;
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
 * @brief Execute the operation of the UtilityPowerPlant
 * 
 * Sets the status to operational
 */
void UtilityPowerPlant::executeOperation() {
	std::cout << "Power Plant is operational." << std::endl;
	this->status = "Operational";
}

/**
 * @brief Get the output of the UtilityPowerPlant
 * 
 * @return float The output of the UtilityPowerPlant
 */
float UtilityPowerPlant::getOutput() {
	return this->Output;
}

/**
 * @brief Set the output of the UtilityPowerPlant
 * 
 * @param Output The output of the UtilityPowerPlant
 * 
 * CHanges the fuel type of the UtilityPowerPlant based on the output
 */
void UtilityPowerPlant::setOutput(float Output) {
	this->Output = Output;
	switchFuel();
}

/**
 * @brief Pause the operation of the UtilityPowerPlant
 * 
 * Sets the status to paused
 */
void UtilityPowerPlant::pauseOperation() {
	std::cout << "Power Plant is being paused..." << std::endl;
	this->status = "Paused";
}

/**
 * @brief Set the max watts of the UtilityPowerPlant
 * 
 * @param max The max watts of the UtilityPowerPlant
 */
void UtilityPowerPlant::setMaxWatts(float max) {
	this->maximumWatts = max;
}

/**
 * @brief Set the fuel of the UtilityPowerPlant
 * 
 * @param fuel The fuel of the UtilityPowerPlant
 */
std::string UtilityPowerPlant::getEnergyType() {
	return this->fuel->getFuelType();
}

/**
 * @brief Get the utility type of the UtilityPowerPlant
 * 
 * @return std::string The utility type of the UtilityPowerPlant
 */
std::string UtilityPowerPlant::getUtilityType() {
	return "Power Plant";
}

/**
 * @brief Switch the fuel of the UtilityPowerPlant
 * 
 * Changes the fuel type of the UtilityPowerPlant based on the current fuel type
 */
void UtilityPowerPlant::switchFuel() {
	if(fuel == nullptr) {
		EnergyFactory *energy = new WindFactory();
		setFuel(energy->createEnergySource(Output));
		delete energy;
		return;
	}
	std::cout <<"Got here"<<std::endl;
	if(fuel->getFuelType() == "Wind") {
		int output = fuel->getEnergyOutput() + 100;
		EnergyFactory *energy = new HydroFactory();
		setFuel(energy->createEnergySource(output));
		delete energy;
	}
	else if(fuel->getFuelType() == "Hydro") {
		int output = fuel->getEnergyOutput() + 500;
		EnergyFactory *energy = new NuclearFactory();
		setFuel(energy->createEnergySource(output));
		delete energy;
	}
	else if(fuel->getFuelType() == "Nuclear") {
		int output = (int)fuel->getEnergyOutput() % 100;
		if(output < 50) output += 50;
		EnergyFactory *energy = new CoalFactory();
		setFuel(energy->createEnergySource(output));
		delete energy;
	}
	else if(fuel->getFuelType() == "Coal") {
		int output = fuel->getEnergyOutput() + 100;
		EnergyFactory *energy = new WindFactory();
		setFuel(energy->createEnergySource(output));
		delete energy;
	}
}

/**
 * @brief Clone the UtilityPowerPlant
 * 
 * @return Utility* The cloned UtilityPowerPlant
 */
Utility* UtilityPowerPlant::clone() {
	UtilityPowerPlant* clone = new UtilityPowerPlant(this->Output);
	clone->setMaxWatts(this->maximumWatts);
	return clone;
}

/**
 * @brief Undo the last change to the UtilityPowerPlant
 * 
 * Undoes the last change to the UtilityPowerPlant
 */
void UtilityPowerPlant::undoChange() {
    int size = commandHistory.size();
    if(size <= 1) {
        std::cout << "No more operations to undo." << std::endl;
        return;
    }
    std::cout << "Last Operation On Powerplant being undone.." << std::endl;
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
 * @brief Set the fuel of the UtilityPowerPlant
 * 
 * @param fuel The fuel of the UtilityPowerPlant
 */
void UtilityPowerPlant::setFuel(EnergySource* fuel2) {
	if(fuel != nullptr) {
		delete fuel;
	}
	this->fuel = fuel2;
	std::cout << "Switching fuel from to " << fuel->getFuelType() << std::endl;
}

/**
 * @brief Destroy the UtilityPowerPlant object
 * 
 * Destroys the UtilityPowerPlant object
 */
UtilityPowerPlant::~UtilityPowerPlant() {
	delete fuel;
	fuel = nullptr;
}

