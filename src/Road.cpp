#include <exception>
#include <string>
using namespace std;

#include "Road.h"
#include "Stops.h"

void Road::road(string aName, float aLength) {
	throw "Not yet implemented";
}

string Road::getSymbol() {
	throw "Not yet implemented";
}

float Road::getDistance() {
	throw "Not yet implemented";
}

void Road::setSpeedLimit(int aLimit) {
	throw "Not yet implemented";
}

int Road::getSpeedLimit() {
	return this->_speedLimit;
}

