#include <exception>
using namespace std;

#ifndef __PassengerTrain_h__
#define __PassengerTrain_h__

// #include "Stops.h"
#include "Train.h"

class Stops;
// class Train;
class PassengerTrain;

class PassengerTrain: public Train
{
	private: int _numPassengers;

	public: int getCapacity();

	public: void getNumPassenger();

	public: void travel(Stops* aDestination);
};

#endif
