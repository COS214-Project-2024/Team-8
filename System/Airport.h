#ifndef AIRPOT_H
#define AIRPOT_H

#include "Stops.h"
/**
 * @file Airport.h
 * 
 * @brief This is the Airport class header file
 */
class Airport : public Stops {

public:
	float ticketCost;

	Airport(std::string name, float length);

	char getSymbol();

	float getDistance();

	void setTicketCost(float cost);

	float getTicketCost();

	std::string getName();
};

#endif
