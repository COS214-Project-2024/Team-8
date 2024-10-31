#include "WaterBuilder.h"

WaterSupply* WaterBuilder::getWaterManager() {
	return dynamic_cast<WaterSupply*>(this->utility);
}

void WaterBuilder::addCommand(Command* com) {
	utility->addCommand(com);
}

void WaterBuilder::setMaxGallons(int max) {
	utility->setMaxGallons(max);
}

WaterBuilder::WaterBuilder(int cursupply) {
	utility = new WaterSupply(cursupply);
}
