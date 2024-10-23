#include <exception>
#include <string>
using namespace std;

#ifndef __TrainStation_h__
#define __TrainStation_h__

#include "Stops.h"

// class Stops;
class TrainStation;

class TrainStation: public Stops
{
	private: float _ticketCost;

	public: void trainStation(string aName, float aLength);

	public: string getSymbol();

	public: float getDistance();

	public: void setTicketCost(float aCost);

	public: float getTicket();
};

#endif
