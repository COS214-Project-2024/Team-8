#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"
/**
 * @file Train.h
 * 
 * @brief This file implements the Train class
 */

class Train : public Transport {
public:
	Train(int capacity);

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
