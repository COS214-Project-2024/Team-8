#ifndef AIRPOT_H
#define AIRPOT_H

#include "Stops.h"
/**
 * @file Airpot.h
 * 
 * @brief This is the Airpot class header file
 */
class Airpot : public Stops {

public:
	float ticketCost;

	Airpot(std::string name, float length);

	char getSymbol();

	float getDistance();

	void setTicketCost(float cost);

	float getTicketCost();

	std::string getName();
};

#endif
