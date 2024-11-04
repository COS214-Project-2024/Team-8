#ifndef TRAVELMANAGER_H
#define TRAVELMANAGER_H

#include "PlaneBuilder.h"
#include "TrainBuilder.h"
#include "VehicleBuilder.h"

#include "AccesibleRoute.h"
#include "BestRouteNode.h"
/**
 * @file TravelManager.h
 * 
 * @brief This file declares the TravelManager class
 */
class TravelManager {

private:
	TransportBuilder* builder;
	float distanceTravelled;
	RouteNode* route;
	Transport* transport;

	void constructCargo(int capacity, float weight);

	void constructPassenger(int capacity, int passengers);

public:
	void Travel(int capacity, Stops* destination, float weight = 0);

	void addStops(Stops* stop);

	~TravelManager();

	TravelManager();

	void BestRoute(int capacity, Stops* destination, float weight = 0);

	void Travel(Transport* trans, Stops* destination);

	void BestRoute(Transport* trans, Stops* destination);
};

#endif
