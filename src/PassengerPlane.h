#include <exception>
using namespace std;

#ifndef __PassengerPlane_h__
#define __PassengerPlane_h__

// #include "Stops.h"
#include "Plane.h"

class Stops;
// class Plane;
class PassengerPlane;

class PassengerPlane: public Plane
{
	private: int _numPassengers;

	public: int getCapacity();

	public: int getNumPassenger();

	public: void travel(Stops* aDestination);

	public: void bestRoute(Stops* aDest);
};

#endif
