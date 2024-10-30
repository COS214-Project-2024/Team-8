#ifndef ROAD_H
#define ROAD_H

#include "Stops.h"
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
