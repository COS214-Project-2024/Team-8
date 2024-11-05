#include "StopCommand.h"

/**
 * @brief Create a StopCommand object
 * 
 * @param utility The utility to stop
 */
StopCommand::StopCommand(Utility* utility) {
	this->utility = utility;
}

/**
 * @brief Execute the command
 * 
 * Stops the utility
 */
void StopCommand::execute() {
	this->utility->pauseOperation();
}

/**
 * @brief Get the utility type of the command
 * 
 * @return std::string The utility type of the command
 */
std::string StopCommand::getUtilityType() {
	return Command::getUtilityType();
}

/**
 * @brief Get the utility of the command
 * 
 * @return Utility* The utility of the command(deep copy)
 */
Utility* StopCommand::getUtility() {
	return Command::getUtility();
}
