#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Command.h"
#include "Utility.h"
class StartCommand : public Command {
public:
	void execute();

	std::string getUtilityType();

	StartCommand(Utility* utility);
};

#endif
