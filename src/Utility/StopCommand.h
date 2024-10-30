#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include "Command.h"
class Utility;
class StopCommand : public Command {
public:
	void execute();

	std::string getUtilityType();

	StopCommand(Utility* utility);
};

#endif
