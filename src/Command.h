#include <exception>
#include <string>
using namespace std;

#ifndef __Command_h__
#define __Command_h__

// #include "UtilityManager.h"

class UtilityManager;
class Command;

class Command
{
	// protected: Utilities* utility;
	public: UtilityManager* utilityMan;

	public: virtual void execute() = 0; // Command Pattern for policies

	public: virtual ~Command() = default; // Command Pattern for policies

	public: string getUtilityType();

	public: Command();
};

#endif
