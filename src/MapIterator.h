#include <exception>
using namespace std;

#ifndef __MapIterator_h__
#define __MapIterator_h__

// #include "RouteNode.h"
// #include "RouteMap.h"
// #include "Stops.h"

class RouteNode;
class RouteMap;
class Stops;
class MapIterator;

class MapIterator
{
	protected: RouteNode* _head;
	protected: RouteNode* _current;

	public: void mapIterator();

	public: MapIterator(RouteMap* aMap, RouteNode* aCur);

	public: Stops* operator_();

	public: RouteNode* operator__(RouteNode* aOther);
};

#endif
