#ifndef PLANE_H
#define PLANE_H

#include "Transport.h"
/**
 * @file Plane.h
 * 
 * @brief This file implements the Plane class
 * 
 * The plane is a type of transport that can travel to stops
 */
class Plane : public Transport {
public:
	Plane(int capacity);

	void setNumPassenger(int pass);

	void setCargoWeight(float weight);

	float travel(Stops* stop, RouteNode* head, bool best = 0);

	std::string getType();

	void setCapacity(int capacity);

	int getCapacity();

	float getWeight();

	int getPassengers();
};

#endif
