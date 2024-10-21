#include <exception>
using namespace std;

#ifndef __AccessibleRoute_h__
#define __AccessibleRoute_h__

// #include "RouteMap.h"
// #include "Stops.h"
#include "RouteNode.h"

class RouteMap;
class Stops;
// class RouteNode;
class AccessibleRoute;

class AccessibleRoute: public RouteNode
{
	public: RouteMap* _head_:_RouteNode_;

	public: void AccessibleRoute(Stops* aData);

	public: void travel(Stops* aDest);

	public: void add(Stops* aData);

	public: float getDistance();
};

#endif
