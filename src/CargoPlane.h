#include <exception>
using namespace std;

#ifndef __CargoPlane_h__
#define __CargoPlane_h__

// #include "Stops.h"
#include "Plane.h"

class Stops;
// class Plane;
class CargoPlane;

class CargoPlane: public Plane
{
	private: float _cargoWeight;

	public: int getCapacity();

	public: float getCargoWeight();

	public: void travel(Stops* aDestination);

	public: void bestRoute(Stops* aDest);
};

#endif
