#include <exception>
using namespace std;

#ifndef __RouteMap_h__
#define __RouteMap_h__

// #include "RouteNode.h"
// #include "Transport.h"
// #include "BestRouteNode.h"
// #include "AccessibleRoute.h"
// #include "Stops.h"

class RouteNode;
class Transport;
class BestRouteNode;
class AccessibleRoute;
class Stops;
class RouteMap;

class RouteMap
{
	private: float _tripDistance;
	private: RouteNode* _head;
	public: Transport* _unnamed_Transport_;
	public: BestRouteNode* _unnamed_BestRouteNode_;
	public: AccessibleRoute* _head_:_RouteNode_;

	public: void travelTo(Stops* aDestination);

	public: bool contains(Stops* aDestination);

	public: float getDistanceTo(Stops* aDestination);

	public: void addStop(Stop* aDestination);

	public: float getDistanceTravelled();

	public: float getTravelTimeEstimate();

	public: RouteNode* getRoute(Stops* aDest);

	public: RouteNode* getShortestRoute(Stops* aDest);
};

#endif
