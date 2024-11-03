#include "PowerPlantBuilder.h"

UtilityPowerPlant* PowerPlantBuilder::getPowerPlant() {
	return dynamic_cast<UtilityPowerPlant*>(this->utility);
}

void PowerPlantBuilder::switchFuel() {
	//EneryFactory *energy = new HydroFactory()
	if(utility->getEnergyType() == "Wind"){
		int output = utility->getCurrentOutput() + 100;
		EnergyFactory *energy = new HydroFactory();
		utility->setFuel(energy->createEnergySource(output));
	}
	else if(utility->getEnergyType() == "Hydro") {
		int output = utility->getCurrentOutput() + 500;
		EnergyFactory *energy = new NuclearFactory();
		utility->setFuel(energy->createEnergySource(output));
	}
	else if(utility->getEnergyType() == "Nuclear") {
		int output = utility->getCurrentOutput() % 100;
		if(output < 50) output += 50;
		EnergyFactory *energy = new CoalFactory();
		utility->setFuel(energy->createEnergySource(output));
	}
	else if(utility->getEnergyType() == "Coal") {
		int output = utility->getCurrentOutput() + 100;
		EnergyFactory *energy = new WindFactory();
		utility->setFuel(energy->createEnergySource(output));
	}

}

void PowerPlantBuilder::addCommand(Command* com) {
	utility->addCommand(com);
}

PowerPlantBuilder::PowerPlantBuilder(int currentOutput) {
	utility = new UtilityPowerPlant(currentOutput);
	EnergyFactory* energy = new CoalFactory(); //Place holder
	if(currentOutput >= 1000) {
		delete energy;
		energy = new NuclearFactory();
	}else if(currentOutput >= 500) {
		delete energy;
		energy = new HydroFactory();
	}else if(currentOutput >= 100) {
		delete energy;
		energy = new WindFactory();
	}
	utility->setFuel(energy->createEnergySource(currentOutput));
	delete energy;
}


void PowerPlantBuilder::setMaxWatts(float max) {
	utility->setMaxWatts(max);
}
