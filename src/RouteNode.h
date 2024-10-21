#include <exception>
using namespace std;

#ifndef __RouteNode_h__
#define __RouteNode_h__

// #include "Stops.h"

class Stops;
class RouteNode;

__abstract class RouteNode
{
	protected: Stops* _data;
	protected: RouteNode* _successor;

	public: void routeNode();

	public: virtual void travel(Stops* aDestination) = 0;

	public: void add(Stops* aData);

	public: float getDistance();

	public: virtual ~RouteNode();
};

#endif
