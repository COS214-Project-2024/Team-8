#include "StartCommand.h"

void StartCommand::execute() {
	this->utility->executeOperation();
}

std::string StartCommand::getUtilityType() {
	return this->utility->getUtilityType();
}

StartCommand::StartCommand(Utility* utility) {
	this->utility = utility;
}
