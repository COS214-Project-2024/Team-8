#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include <string>
#include "Command.h"
/**
 * @file StopCommand.h
 * 
 * @brief The header file for the StopCommand class
 */
class StopCommand : public Command {
public:
	StopCommand(Utility* utility);

	void execute();

	std::string getUtilityType();

	Utility* getUtility();
};

#endif
