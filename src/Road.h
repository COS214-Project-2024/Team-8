#include <exception>
#include <string>
using namespace std;

#ifndef __Road_h__
#define __Road_h__

#include "Stops.h"

// class Stops;
class Road;

class Road: public Stops
{
	private: int _speedLimit;

	public: void road(string aName, float aLength);

	public: string getSymbol();

	public: float getDistance();

	public: void setSpeedLimit(int aLimit);

	public: int getSpeedLimit();
};

#endif
