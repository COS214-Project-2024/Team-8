#include <exception>
#include <string>
using namespace std;

#ifndef __Command_h__
#define __Command_h__

// #include "UtilityManager.h"

class UtilityManager;
class Command;

__abstract class Command
{
	protected: Utilities* _utility;
	public: UtilityManager* _unnamed_UtilityManager_;

	public: virtual void execute() = 0;

	public: virtual ~Command();

	public: string getUtilityType();

	public: Command();
};

#endif
