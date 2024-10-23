#include <exception>
using namespace std;

#ifndef __Plane_h__
#define __Plane_h__

// #include "Stops.h"
#include "Transport.h"

class Stops;
// class Transport;
class Plane;

__abstract class Plane: public Transport
{

	public: void plane(Stops* aDestination);

	public: void travel(Stops* aDestination);

	public: int getCapacity();

	public: float getCargoWeight();

	public: bool isReachable(Stops* aDest);

	public: void bestRoute(Stops* aDest);
};

#endif
