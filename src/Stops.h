#include <exception>
#include <string>
using namespace std;

#ifndef __Stops_h__
#define __Stops_h__

// #include "TravelManager.h"

class TravelManager;
class Stops;

class Stops
{
	private: Char _symbol;
	private: float _lengthOfStop;
	private: string _stopName;
	public: TravelManager* _unnamed_TravelManager_;

	public: float getCost();

	public: string getSymbol();

	public: float getDistance();

	public: void setTicketCost(float aCost);

	public: float getTicketCost();
};

#endif
