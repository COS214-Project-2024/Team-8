#ifndef BESTROUTENODE_H
#define BESTROUTENODE_H

#include "RouteNode.h"
class BestRouteNode : public RouteNode {
public:
	BestRouteNode();

	void add(Stops* data);

	float getDistance();

	Stops* getData();

	RouteNode* travel();
};

#endif
