#include <exception>
using namespace std;

#ifndef __WaterBuilder_h__
#define __WaterBuilder_h__

// #include "WaterSupply.h"
// #include "Command.h"
#include "UtilityBuilder.h"

class WaterSupply;
class Command;
// class UtilityBuilder;
class WaterBuilder;

class WaterBuilder: public UtilityBuilder
{

	public: WaterSupply* getWaterManagerr();

	public: void addCommand(Command* aCom);

	public: void setMaxGallons(int aMax);

	public: WaterBuilder(int aCurSuplly);
};

#endif
