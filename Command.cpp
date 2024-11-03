#include "Command.h"

/**
 * @brief Get the utility type of the command
 * 
 * @return std::string The utility type of the command
 */
std::string Command::getUtilityType() {
	return this->utility->getUtilityType();
}

/**
 * @brief Get the utility of the command
 * 
 * @return Utility* The utility of the command
 */
Utility* Command::getUtility() {
	return this->utility->clone();
}

/**
 * @brief Destroy the Command object
 * 
 */
Command::~Command() {
	std::cout << "Command destroyed" << std::endl;
}
