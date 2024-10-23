#ifndef ACCESIBLEROUTE_H
#define ACCESIBLEROUTE_H

#include "RouteNode.h"
class AccesibleRoute : public RouteNode {
public:
	AccesibleRoute();

	void add(Stops* data);

	float getDistance();

	Stops* getData();

	RouteNode* travel();
};

#endif
