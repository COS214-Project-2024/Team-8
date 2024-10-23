#include <exception>
#include <string>
using namespace std;

#ifndef __StopCommand_h__
#define __StopCommand_h__

#include "Command.h"

// class Command;
class StopCommand;

class StopCommand: public Command
{

	public: void execute();

	public: string getUtilityType();

	public: StopCommand(Utilities* aUtility);
};

#endif
