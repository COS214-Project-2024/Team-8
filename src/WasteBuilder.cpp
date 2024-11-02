#include "WasteBuilder.h"

WasteManagement* WasteBuilder::getWasteManager() {
	return dynamic_cast<WasteManagement *>(this->utility);
}

WasteBuilder::WasteBuilder(int curload) {
	this->utility = new WasteManagement(curload);
}

void WasteBuilder::addCommand(Command* com) {
	this->utility->addCommand(com);
}

void WasteBuilder::setCapacity(int max) {
	this->utility->setProcessCapacity(max);
}
