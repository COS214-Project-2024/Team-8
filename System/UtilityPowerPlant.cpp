#include "UtilityPowerPlant.h"


UtilityPowerPlant::UtilityPowerPlant(float output) {
	this->Output = output;
	this->maximumWatts = output * 2;
	this->fuel = nullptr;
	switchFuel();
}


std::string UtilityPowerPlant::getStatus() {
	return this->status;
}


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


void UtilityPowerPlant::executeOperation() {
	std::cout << "Power Plant is operational." << std::endl;
	this->status = "Operational";
}


float UtilityPowerPlant::getOutput() {
	return this->Output;
}


void UtilityPowerPlant::setOutput(float Output) {
	this->Output = Output;
	switchFuel();
}


void UtilityPowerPlant::pauseOperation() {
	std::cout << "Power Plant is being paused..." << std::endl;
	this->status = "Paused";
}


void UtilityPowerPlant::setMaxWatts(float max) {
	this->maximumWatts = max;
}


std::string UtilityPowerPlant::getEnergyType() {
	return this->fuel->getFuelType();
}


std::string UtilityPowerPlant::getUtilityType() {
	return "Power Plant";
}


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


Utility* UtilityPowerPlant::clone() {
	UtilityPowerPlant* clone = new UtilityPowerPlant(this->Output);
	clone->setMaxWatts(this->maximumWatts);
	return clone;
}


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


void UtilityPowerPlant::setFuel(EnergySource* fuel2) {
	if(fuel != nullptr) {
		delete fuel;
	}
	this->fuel = fuel2;
	std::cout << "Switching fuel from to " << fuel->getFuelType() << std::endl;
}


UtilityPowerPlant::~UtilityPowerPlant() {
	delete fuel;
	fuel = nullptr;
}


bool UtilityPowerPlant::getPower(Buildings* sender) {
	int size = buildings.size();
	for(int i = 0; i < size; i++) {
		if(buildings[i] == sender) {
			//sender->setPower(getOutput());

			std::cout << this->Output << std::endl;

			return true;
		}
	}

	std::cout << "Building is not registered" << std::endl;

	return false;
}


void UtilityPowerPlant::addBuilding(Buildings* building) {
	this->buildings.push_back(building);
}

