#include <exception>
using namespace std;

#include "UtilityBuilder.h"
#include "Utility.h"
#include "UtilityDirector.h"
#include "WaterSupply.h"
#include "Command.h"

WaterSupply* UtilityBuilder::getWaterManager() {
	throw "Not yet implemented";
}

WasterManagement* UtilityBuilder::getWasterManager() {
	throw "Not yet implemented";
}

SewageSystem* UtilityBuilder::getSewageSystem() {
	throw "Not yet implemented";
}

void UtilityBuilder::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void UtilityBuilder::setMaxWaste(int aMax) {
	throw "Not yet implemented";
}

void UtilityBuilder::setCapacity(int aMax) {
	throw "Not yet implemented";
}

void UtilityBuilder::setMaxGallons(int aMax) {
	throw "Not yet implemented";
}

void UtilityBuilder::setMaxWatts(float aMax) {
	throw "Not yet implemented";
}

void UtilityBuilder::switchFuel() {
	throw "Not yet implemented";
}

UtilityBuilder::UtilityBuilder() {
}

UtilityBuilder::~UtilityBuilder() {
	throw "Not yet implemented";
}

