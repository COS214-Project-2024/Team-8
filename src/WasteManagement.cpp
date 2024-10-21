#include <exception>
#include <string>
using namespace std;

#include "WasteManagement.h"
#include "Command.h"
#include "Utility.h"

void WasteManagement::wasteManagement(int aCurload) {
	throw "Not yet implemented";
}

string WasteManagement::getStatus() {
	throw "Not yet implemented";
}

void WasteManagement::repairUtility() {
	throw "Not yet implemented";
}

void WasteManagement::executeOperation() {
	throw "Not yet implemented";
}

int WasteManagement::getCurrentLoad() {
	throw "Not yet implemented";
}

void WasteManagement::pauseOperation() {
	throw "Not yet implemented";
}

void WasteManagement::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void WasteManagement::setProcessCapacity(int aPro) {
	this->_processCapacity = aPro;
}

