#include <exception>
using namespace std;

#ifndef __Transport_h__
#define __Transport_h__

// #include "TravelManager.h"
// #include "Citizen.h"
// #include "RouteMap.h"
// #include "Stops.h"

class TravelManager;
class Citizen;
class RouteMap;
class Stops;
class Transport;

__abstract class Transport
{
	protected: RouteMap* _routes;
	protected: int _capacity;
	public: TravelManager* _unnamed_TravelManager_;
	public: Citizen* _unnamed_Citizen_;
	public: RouteMap* _unnamed_RouteMap_;

	public: virtual void travel(Stops* aDestination) = 0;

	public: int getCapacity();

	public: float getCargoWeight();

	public: bool isReachable(Stops* aDestination);

	public: void bestRoute(Stops* aDest);

	public: virtual ~Transport();
};

#endif
