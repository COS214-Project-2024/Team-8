#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "Command.h"
/**
 * @file UndoCommand.h
 * 
 * @brief The header file for the StopCommand class
 */
class UndoCommand : public Command {
public:
	UndoCommand(Utility* utility);

	void execute();

	std::string getUtilityType();

	Utility* getUtility();
};

#endif