#include <exception>
#include <string>
using namespace std;

#ifndef __WaterSupply_h__
#define __WaterSupply_h__

// #include "Command.h"
#include "Utility.h"

class Command;
// class Utility;
class WaterSupply;

class WaterSupply: public Utility
{
	private: int _maxGallons;
	private: float _puritypercentage;
	private: int _currentSupply;

	public: void waterSupply(int aCurSupply);

	public: string getStatus();

	public: void reapirUtility();

	public: void executeOperation();

	public: int getCurrentSupply();

	public: void pauseOperation();

	public: void addCommand(Command* aCom);

	public: void setMaxGallons(float aMax);

	public: virtual void repairUtility();
};

#endif
