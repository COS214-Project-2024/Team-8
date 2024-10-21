#include <exception>
#include <vector>
using namespace std;

#ifndef __ResourceMediator_h__
#define __ResourceMediator_h__

// #include "Resources.h"
#include "CitySector.h"

class Resources;
class CitySector;
class ResourceMediator;

class ResourceMediator
{
	private: Vector<Resources*> _resources;
	private: Vector<CitySector*> _citySectors;
	public: Resources* _unnamed_Resources_;
	public: CitySector* _unnamed_CitySector_;

	public: ResourceMediator(vector<Resources*> aResources);

	public: bool usePower(double aUnits, CitySector aSender);

	public: void replenishPower(double aUnits);

	public: bool useRevenue(double aUnits, CitySector aSender);

	public: void replenishRevenue(double aUnits);

	public: bool useWater(double aUnits, CitySector aSender);

	public: void replenishWater(double aUnits);

	public: bool cleanWaste(double aUnits, CitySector aSender);

	public: void gainWaste(double aUnits);

	public: bool cleanSewage(double aUnits, CitySector aSender);

	public: void gainSewage(double aUnits);

	public: void outOfPower();

	public: void outOfWater();

	public: void outOfRevenue();

	public: void outOfWasteMan();

	public: void outOfSewageMan();
};

#endif
