#include <exception>
#include <string>
using namespace std;

#include "Utility.h"
#include "UtilityManager.h"
#include "City.h"
#include "Command.h"

string Utility::getStatus() {
	return this->_status;
}

void Utility::executeOperation() {
	throw "Not yet implemented";
}

void Utility::repairUtility() {
	throw "Not yet implemented";
}

string Utility::getEnergyType() {
	throw "Not yet implemented";
}

int Utility::getCurrentSupply() {
	throw "Not yet implemented";
}

int Utility::getCurrentLoad() {
	throw "Not yet implemented";
}

void Utility::undoChange() {
	throw "Not yet implemented";
}

void Utility::pauseOperation() {
	throw "Not yet implemented";
}

void Utility::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

Utility::~Utility() {
	throw "Not yet implemented";
}

Utility::Utility() {
}

