#include <exception>
using namespace std;

#ifndef __BestRouteNode_h__
#define __BestRouteNode_h__

// #include "RouteMap.h"
// #include "Stops.h"
#include "RouteNode.h"

class RouteMap;
class Stops;
// class RouteNode;
class BestRouteNode;

class BestRouteNode: public RouteNode
{
	public: RouteMap* _unnamed_RouteMap_;

	public: void bestRouteNode(Stops* aData);

	public: void travel(Stops* aDest);

	public: void add(Stops* aData);

	public: float getDistance();
};

#endif
