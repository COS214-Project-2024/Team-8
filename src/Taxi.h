#include <exception>
using namespace std;

#ifndef __Taxi_h__
#define __Taxi_h__

// #include "Stops.h"
#include "Transport.h"

class Stops;
// class Transport;
class Taxi;

class Taxi: public Transport
{

	public: void taxi(Stops* aDestination);

	public: void travel(Stops* aDestination);

	public: int getCapacity();

	public: bool isReachable(Stops* aDest);

	public: void bestRoute(Stops* aDest);
};

#endif
