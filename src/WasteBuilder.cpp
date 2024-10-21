#include <exception>
using namespace std;

#include "WasteBuilder.h"
#include "WasteManagement.h"
#include "Command.h"
#include "UtilityBuilder.h"

WasteManagement* WasteBuilder::getWasteManager() {
	throw "Not yet implemented";
}

WasteBuilder::WasteBuilder(int aCurload) {
}

void WasteBuilder::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void WasteBuilder::setCapacity(int aMax) {
	throw "Not yet implemented";
}

