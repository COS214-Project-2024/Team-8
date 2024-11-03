#include "UndoCommand.h"

/**
 * @brief Create a UndoCommand object
 * 
 * @param utility The utility to Undo
 */
UndoCommand::UndoCommand(Utility* utility) {
	this->utility = utility;
}

/**
 * @brief Execute the command
 * 
 * Undos the utility
 */
void UndoCommand::execute() {
	this->utility->pauseOperation();
}

/**
 * @brief Get the utility type of the command
 * 
 * @return std::string The utility type of the command
 */
std::string UndoCommand::getUtilityType() {
	return Command::getUtilityType();
}

/**
 * @brief Get the utility of the command
 * 
 * @return Utility* The utility of the command(deep copy)
 */
Utility* UndoCommand::getUtility() {
	return Command::getUtility();
}
