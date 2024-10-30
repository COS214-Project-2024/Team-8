#include "Road.h"

Road::Road(std::string name, float length) {
	this->name = name;
	this->length = length;
	this->symbol = 'R';
}

char Road::getSymbol() {
	return this->symbol;
}

float Road::getDistance() {
	return this->length;
}

void Road::setSpeedLimit(int limit) {
	this->speedLimit = limit;
}

int Road::getSpeedLimit() {
	return this->speedLimit;
}

std::string Road::getName() {
	return Stops::getName();
}
