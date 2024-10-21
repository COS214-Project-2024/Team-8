#include <exception>
using namespace std;

#ifndef __Train_h__
#define __Train_h__

// #include "Stops.h"
#include "Transport.h"

class Stops;
// class Transport;
class Train;

__abstract class Train: public Transport
{

	public: void train(Stops* aDestination);

	public: void travel(Stops* aDestination);

	public: int getCapacity();

	public: float getCargoWeight();

	public: bool isReachable(Stops* aDest);
};

#endif
