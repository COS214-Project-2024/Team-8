#include <exception>
using namespace std;

#include "RouteMap.h"
#include "RouteNode.h"
#include "Transport.h"
#include "BestRouteNode.h"
#include "AccessibleRoute.h"
#include "Stops.h"

void RouteMap::travelTo(Stops* aDestination) {
	throw "Not yet implemented";
}

bool RouteMap::contains(Stops* aDestination) {
	throw "Not yet implemented";
}

float RouteMap::getDistanceTo(Stops* aDestination) {
	throw "Not yet implemented";
}

void RouteMap::addStop(Stop* aDestination) {
	throw "Not yet implemented";
}

float RouteMap::getDistanceTravelled() {
	throw "Not yet implemented";
}

float RouteMap::getTravelTimeEstimate() {
	throw "Not yet implemented";
}

RouteNode* RouteMap::getRoute(Stops* aDest) {
	throw "Not yet implemented";
}

RouteNode* RouteMap::getShortestRoute(Stops* aDest) {
	throw "Not yet implemented";
}

