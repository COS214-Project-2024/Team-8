#include <exception>
#include <string>
using namespace std;

#ifndef __Utility_h__
#define __Utility_h__

// #include "UtilityManager.h"
// #include "City.h"
// #include "Command.h"

class UtilityManager;
class City;
class Command;
class Utility;

__abstract class Utility
{
	protected: string _status;
	protected: Buildings* _buildinglist;
	protected: UtilityManager* _manager;
	public: UtilityManager* _unnamed_UtilityManager_;
	public: City* _unnamed_City_;

	public: string getStatus();

	public: virtual void executeOperation() = 0;

	public: virtual void repairUtility() = 0;

	public: string getEnergyType();

	public: int getCurrentSupply();

	public: int getCurrentLoad();

	public: void undoChange();

	public: void pauseOperation();

	public: void addCommand(Command* aCom);

	public: virtual ~Utility();

	public: Utility();
};

#endif
