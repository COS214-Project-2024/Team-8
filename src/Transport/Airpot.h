#ifndef AIRPOT_H
#define AIRPOT_H

#include "Stops.h"
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
