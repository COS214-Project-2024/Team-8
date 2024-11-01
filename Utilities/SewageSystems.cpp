#include <exception>
#include <string>
using namespace std;

#include "SewageSystems.h"
#include "Command.h"

SewageSystems::SewageSystems(int curloat)
{
	this.currentload = curloat ; 
}

string SewageSystems::getStatus()
{
    throw "Not yet implemented";
}


void SewageSystems::executeOperation() {
	throw "Not yet implemented";
}

int SewageSystems::getCurrentLoad() {
	return this.currentload ; 
}

void SewageSystems::pauseOperation() {
	throw "Not yet implemented";
}

void SewageSystems::addCommand(Command* aCom) {
	throw "Not yet implemented";
}

void SewageSystems::setmaxWaste(int aMax) {
	throw "Not yet implemented";
}

void SewageSystems::repairUtility() {
	throw "Not yet implemented";
}

