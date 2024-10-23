#include <exception>
#include <string>
using namespace std;

#include "StopCommand.h"
#include "Command.h"

void StopCommand::execute() {
	throw "Not yet implemented";
}

string StopCommand::getUtilityType() {
	throw "Not yet implemented";
}

StopCommand::StopCommand(Utilities* aUtility) {
}

