#ifndef COMMAND_H
#define COMMAND_H

#include "Utility.h"
/**
 * @file Command.h
 * 
 * @brief The header file for the Command class
 */
class Command {
protected:
	Utility* utility;

public:
	virtual void execute() = 0;

	virtual std::string getUtilityType();

	virtual Utility* getUtility();

	virtual ~Command();
};

#endif
