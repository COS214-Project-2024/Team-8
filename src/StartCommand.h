#include <exception>
#include <string>
using namespace std;

#ifndef __StartCommand_h__
#define __StartCommand_h__

#include "Command.h"

// class Command;
class StartCommand;

class StartCommand: public Command
{

	public: void execute();

	public: string getUtilityType();

	public: StartCommand(Utilities* aUtility);
};

#endif
