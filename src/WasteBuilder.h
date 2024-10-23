#include <exception>
using namespace std;

#ifndef __WasteBuilder_h__
#define __WasteBuilder_h__

// #include "WasteManagement.h"
// #include "Command.h"
#include "UtilityBuilder.h"

class WasteManagement;
class Command;
// class UtilityBuilder;
class WasteBuilder;

class WasteBuilder: public UtilityBuilder
{

	public: WasteManagement* getWasteManager();

	public: WasteBuilder(int aCurload);

	public: void addCommand(Command* aCom);

	public: void setCapacity(int aMax);
};

#endif
