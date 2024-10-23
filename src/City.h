#include <exception>
#include <vector>
using namespace std;

#ifndef __City_h__
#define __City_h__

// #include "CitySector.h"
// #include "ResourceMediator.h"
// #include "Utility.h"
// #include "PopulationControl.h"
// #include "Citizen.h"
// #include "TravelManager.h"

class CitySector;
class ResourceMediator;
class Utility;
class PopulationControl;
class Citizen;
class TravelManager;
class City;

class City
{
	private: CitySector* _sectors;
	private: int _totalPower;
	private: vector<Resources*> _resources;
	private: ResourceMediator* _resourceMediator;
	private: int _totalWasteManagement;
	private: int _totalSewageMangement;
	private: int _totalWatterSupply;
	private: double _totalIncome;
	private: PopulationControl* _population;
	public: Utility* _unnamed_Utility_;
	public: PopulationControl* _unnamed_PopulationControl_;
	public: Citizen* _unnamed_Citizen_;
	public: TravelManager* _unnamed_TravelManager_;

	public: void runSimulation();
};

#endif
