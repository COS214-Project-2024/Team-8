#include <exception>
#include <string>
using namespace std;

#include "Airpot.h"
#include "Stops.h"

void Airpot::airpot(string aName, float aLength) {
	throw "Not yet implemented";
}

string Airpot::getSymbol() {
	throw "Not yet implemented";
}

float Airpot::getDistance() {
	throw "Not yet implemented";
}

void Airpot::setTicketCost(float aCost) {
	this->_ticketCost = aCost;
}

float Airpot::getTicketCost() {
	return this->_ticketCost;
}

