#include "StartCommand.h"

/**
 * @brief Create a StartCommand object
 * 
 * @param utility The utility to start
 */
StartCommand::StartCommand(Utility* utility) {
	this->utility = utility;
}

/**
 * @brief Execute the command
 * 
 * Starts the utility
 */
void StartCommand::execute() {
	this->utility->executeOperation();
}

/**
 * @brief Get the utility type of the command
 * 
 * @return std::string The utility type of the command
 */
std::string StartCommand::getUtilityType() {
	return Command::getUtilityType();
}

/**
 * @brief Get the utility of the command
 * 
 * @return Utility* The utility of the command(deep copy)
 */
Utility* StartCommand::getUtility() {
	return Command::getUtility();
}
