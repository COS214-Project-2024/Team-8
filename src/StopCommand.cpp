#include "StopCommand.h"

void StopCommand::execute() {
	this->utility->pauseOperation();
}

std::string StopCommand::getUtilityType() {
	this->utility->getUtilityType();
}

StopCommand::StopCommand(Utility* utility) {
	this->utility = utility;
}
