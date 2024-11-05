#ifndef BESTROUTENODE_H
#define BESTROUTENODE_H

#include "RouteNode.h"
/**
 * @class BestRouteNode
 * @brief A node in the route tree that keeps track of the best route
 *
 * The BestRouteNode class is a subclass of RouteNode that keeps track of the best route to add
 * Specific stops to the route and calculate the distance based in stops.
 * 
 */
class BestRouteNode : public RouteNode {
public:
	BestRouteNode();

	void add(Stops* data);

	float getDistance();

	Stops* getData();

	RouteNode* travel();
};

#endif
