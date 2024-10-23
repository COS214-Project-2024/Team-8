#include <exception>
using namespace std;

#ifndef __CityController_h__
#define __CityController_h__

// #include "Resources.h"
// #include "PopulationControl.h"
// #include "Citizen.h"

class Resources;
class PopulationControl;
class Citizen;
class CityController;

class CityController
{

	public: Builder* createBuilding();

	public: Resources* buildInfrastructure();

	public: void provideUtilities();

	public: void addDecorations();

	public: PopulationControl* evaluatePopulationGrowth();

	public: Citizen* handleCitizenNeedsAndSatisfaction();

	public: Policy* evaluatePolicies();

	public: void update();
};

#endif
