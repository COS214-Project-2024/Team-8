#ifndef ACCESIBLEROUTE_H
#define ACCESIBLEROUTE_H

#include "RouteNode.h"
/**
 * @file AccesibleRoute.h
 * 
 * @brief This is the AccesibleRoute class header file
 */
class AccesibleRoute : public RouteNode {
public:
	AccesibleRoute();

	void add(Stops* data);

	float getDistance();

	Stops* getData();

	RouteNode* travel();
};

#endif
