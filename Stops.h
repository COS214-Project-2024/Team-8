#ifndef STOPS_H
#define STOPS_H

#include <iostream>
/**
 * @file Stops.h
 * 
 * @brief This file implements the Stops class
 */
class Stops {
protected:
	char symbol;
	float length;
	std::string name;

public:
	virtual float getCost();

	virtual char getSymbol() = 0;

	virtual float getDistance() = 0;

	virtual void setTicketCost(float cost);

	virtual float getTicketCost();

	virtual std::string getName();

	virtual void setSpeedLimit(int limit);

	virtual int getSpeedLimit();
};

#endif
