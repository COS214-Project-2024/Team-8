#ifndef VEHICLE_H
#define VEHICLE_H

#include "Transport.h"
class Vehicle : public Transport {
public:
	Vehicle(int capacity);

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
