#include <exception>
using namespace std;

#ifndef __Bus_h__
#define __Bus_h__

// #include "Stops.h"
#include "Transport.h"

class Stops;
// class Transport;
class Bus;

class Bus: public Transport
{

	public: void bus(Stops* aDestination);

	public: void travel(Stops* aDestination);

	public: int getCapacity();

	public: bool isReachable(Stops* aDest);

	public: void bestRoute(Stops* aDest);
};

#endif
