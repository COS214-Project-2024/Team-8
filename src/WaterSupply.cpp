#include <exception>
#include <string>
using namespace std;

#include "WaterSupply.h"
#include "Command.h"
#include "Utility.h"

void WaterSupply::waterSupply(int aCurSupply) {
	throw "Not yet implemented";
}

string WaterSupply::getStatus() {
	throw "Not yet implemented";
}

void WaterSupply::reapirUtility() {
	throw "Not yet implemented";
}

void WaterSupply::executeOperation() {
	throw "Not yet implemented";
}

int WaterSupply::getCurrentSupply() {
	return this->_currentSupply;
}

void WaterSupply::pauseOperation() {
	throw "Not yet implemented";
}

void WaterSupply::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void WaterSupply::setMaxGallons(float aMax) {
	throw "Not yet implemented";
}

void WaterSupply::repairUtility() {
	throw "Not yet implemented";
}

