#include <exception>
using namespace std;

#include "PowerPlantBuilder.h"
#include "EnergyFactory.h"
#include "PowerPlant.h"
#include "Command.h"
#include "UtilityBuilder.h"

PowerPlant* PowerPlantBuilder::getPowerPlant() {
	throw "Not yet implemented";
}

void PowerPlantBuilder::switchFuel() {
	throw "Not yet implemented";
}

void PowerPlantBuilder::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

PowerPlantBuilder::PowerPlantBuilder(int aCurrentOutput) {
}

void PowerPlantBuilder::setMaxWatts(float aMax) {
	throw "Not yet implemented";
}

