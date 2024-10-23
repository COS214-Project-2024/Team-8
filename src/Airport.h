#include <exception>
#include <string>
using namespace std;

#ifndef __Airpot_h__
#define __Airpot_h__

#include "Stops.h"

// class Stops;
class Airpot;

class Airpot: public Stops
{
	private: float _ticketCost;

	public: void airpot(string aName, float aLength);

	public: string getSymbol();

	public: float getDistance();

	public: void setTicketCost(float aCost);

	public: float getTicketCost();
};

#endif
