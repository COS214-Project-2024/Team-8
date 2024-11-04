#ifndef ROAD_H
#define ROAD_H

#include "Stops.h"

/**
 * @file Road.h
 * 
 * @brief This file implements the Road class
 * 
 * The Road class is a subclass of the Stops class
 */

class Road : public Stops {

public:
	int speedLimit;

	Road(std::string name, float length);

	char getSymbol();

	float getDistance();

	void setSpeedLimit(int limit);

	int getSpeedLimit();

	std::string getName();
};

#endif
