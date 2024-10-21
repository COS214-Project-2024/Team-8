#include <exception>
using namespace std;

#include "CargoPlane.h"
#include "Stops.h"
#include "Plane.h"

int CargoPlane::getCapacity() {
	throw "Not yet implemented";
}

float CargoPlane::getCargoWeight() {
	return this->_cargoWeight;
}

void CargoPlane::travel(Stops* aDestination) {
	throw "Not yet implemented";
}

void CargoPlane::bestRoute(Stops* aDest) {
	throw "Not yet implemented";
}

