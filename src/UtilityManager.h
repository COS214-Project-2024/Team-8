#include <exception>
using namespace std;

#ifndef __UtilityManager_h__
#define __UtilityManager_h__

// #include "Command.h"
// #include "Utility.h"
// #include "Command.h"

class Command;
class Utility;
class Command;
class UtilityManager;

class UtilityManager
{
	private: Command* _history;
	public: Utility* _unnamed_Utility_;
	public: Command* _unnamed_Command_;

	public: UtilityManager();

	public: void executeWaste();

	public: void undoCommand();

	public: void loadShedding();

	public: void unfilledDam();

	public: void executeSewage();

	public: void executeWater();

	public: void executeElectricity();

	public: void addCommand(Command* aCom);
};

#endif
