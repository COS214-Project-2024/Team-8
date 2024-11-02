#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "Stops.h"
/**
 * @file TrainStation.h
 * 
 * @brief This file declares the TrainStation class
 */
class TrainStation : public Stops {

public:
	float ticketCost;

	TrainStation(std::string name, float length);

	char getSymbol();

	float getDistance();

	void setTicketCost(float cost);

	float getTicket();

	std::string getName();
};

#endif
