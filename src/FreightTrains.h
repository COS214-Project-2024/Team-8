#include <exception>
using namespace std;

#ifndef __FreightTrains_h__
#define __FreightTrains_h__

// #include "Stops.h"
#include "Train.h"

class Stops;
// class Train;
class FreightTrains;

class FreightTrains: public Train
{
	private: float _cargoWeight;

	public: int getCapacity();

	public: float getCargoWeight();

	public: void travel(Stops* aDestination);
};

#endif
