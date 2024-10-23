#include <exception>
#include <string>
using namespace std;

#include "StartCommand.h"
#include "Command.h"

void StartCommand::execute() {
	throw "Not yet implemented";
}

string StartCommand::getUtilityType() {
	throw "Not yet implemented";
}

StartCommand::StartCommand(Utilities* aUtility) {
}

