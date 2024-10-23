#include "TrainStation.h"

TrainStation::TrainStation(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'T';
}

char TrainStation::getSymbol() {
	return this->symbol;
}

float TrainStation::getDistance() {
	return this->length;
}

void TrainStation::setTicketCost(float cost) {
	this->ticketCost = cost;
}

float TrainStation::getTicket() {
	return this->ticketCost;
}

std::string TrainStation::getName() {
	return Stops::getName();
}


