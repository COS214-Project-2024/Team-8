#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Command.h"
/**
 * @file StartCommand.h
 * 
 * @brief The header file for the StartCommand class
 */
class StartCommand : public Command {
public:
	StartCommand(Utility* utility);

	void execute();

	std::string getUtilityType();

	Utility* getUtility();
};

#endif
