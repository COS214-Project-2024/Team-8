#include <exception>
#include <string>
using namespace std;

#ifndef __SewageSystems_h__
#define __SewageSystems_h__

// #include "Command.h"
#include "Utility.h"

class Command;
// class Utility;
class SewageSystems;

class SewageSystems: public Utility
{
	private: int _maxWaste;
	private: float _blockagepercentage;
	private: int _currentload;

	public: void sewageSystems(int aCurloat);

	public: string getStatus();

	public: void repareUtility();

	public: void executeOperation();

	public: int getCurrentLoad();

	public: void pauseOperation();

	public: void addCommand(Command* aCom);

	public: void setmaxWaste(int aMax);

	public: virtual void repairUtility();
};

#endif
