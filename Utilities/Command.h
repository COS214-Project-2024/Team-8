#ifndef COMMAND_H
#define COMMAND_H

#include "Utility.h"
class Command {
protected:
	Utility* utility = nullptr;
public:
	virtual void execute() = 0;

	virtual ~Command();

	virtual std::string getUtilityType() = 0;
};

#endif
