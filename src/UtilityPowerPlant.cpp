#include <exception>
#include <string>
using namespace std;

#include "UtilityPowerPlant.h"
#include "Command.h"
#include "EnergySource.h"
#include "Utility.h"

UtilityPowerPlant::UtilityPowerPlant(int aOutput) {
}

string UtilityPowerPlant::getEnergyType() {
	throw "Not yet implemented";
}

void UtilityPowerPlant::executeOperation() {
	throw "Not yet implemented";
}

void UtilityPowerPlant::repareUtility() {
	throw "Not yet implemented";
}

string UtilityPowerPlant::getStatus() {
	throw "Not yet implemented";
}

void UtilityPowerPlant::pauseOperation() {
	throw "Not yet implemented";
}

void UtilityPowerPlant::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void UtilityPowerPlant::setMaxWatts(float aMax) {
	throw "Not yet implemented";
}

void UtilityPowerPlant::setFuel(EnergySource* aFuel) {
	throw "Not yet implemented";
}

void UtilityPowerPlant::repairUtility() {
	throw "Not yet implemented";
}

