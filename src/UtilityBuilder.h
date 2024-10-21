#include <exception>
using namespace std;

#ifndef __UtilityBuilder_h__
#define __UtilityBuilder_h__

// #include "Utility.h"
// #include "UtilityDirector.h"
// #include "WaterSupply.h"
// #include "Command.h"

class Utility;
class UtilityDirector;
class WaterSupply;
class Command;
class UtilityBuilder;

__abstract class UtilityBuilder
{
	protected: Utility* _utility;
	public: UtilityDirector* _unnamed_UtilityDirector_;

	public: WaterSupply* getWaterManager();

	public: WasterManagement* getWasterManager();

	public: SewageSystem* getSewageSystem();

	public: virtual void addCommand(Command* aCom) = 0;

	public: void setMaxWaste(int aMax);

	public: void setCapacity(int aMax);

	public: void setMaxGallons(int aMax);

	public: void setMaxWatts(float aMax);

	public: void switchFuel();

	public: UtilityBuilder();

	public: virtual ~UtilityBuilder();
};

#endif
