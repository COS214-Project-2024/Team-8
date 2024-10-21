#include <exception>
using namespace std;

#include "Transport.h"
#include "TravelManager.h"
#include "Citizen.h"
#include "RouteMap.h"
#include "Stops.h"

void Transport::travel(Stops* aDestination) {
	throw "Not yet implemented";
}

int Transport::getCapacity() {
	return this->_capacity;
}

float Transport::getCargoWeight() {
	throw "Not yet implemented";
}

bool Transport::isReachable(Stops* aDestination) {
	throw "Not yet implemented";
}

void Transport::bestRoute(Stops* aDest) {
	throw "Not yet implemented";
}

Transport::~Transport() {
	throw "Not yet implemented";
}

