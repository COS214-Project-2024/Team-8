#include <exception>
#include <string>
using namespace std;

#ifndef __WasteManagement_h__
#define __WasteManagement_h__

// #include "Command.h"
#include "Utility.h"

class Command;
// class Utility;
class WasteManagement;

class WasteManagement: public Utility
{
	private: int _processCapacity;
	private: int _currentload;
	private: float _recycledperc;

	public: void wasteManagement(int aCurload);

	public: string getStatus();

	public: void repairUtility();

	public: void executeOperation();

	public: int getCurrentLoad();

	public: void pauseOperation();

	public: void addCommand(Command* aCom);

	public: void setProcessCapacity(int aPro);
};

#endif
