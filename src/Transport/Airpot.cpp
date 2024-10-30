#include "Airpot.h"

Airpot::Airpot(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'A';
}

char Airpot::getSymbol() {
	return this->symbol;
}

float Airpot::getDistance() {
	return this->length;
}

void Airpot::setTicketCost(float cost) {
	this->ticketCost = cost;
}

float Airpot::getTicketCost() {
	return this->ticketCost;
}

std::string Airpot::getName() {
	return Stops::getName();
}
